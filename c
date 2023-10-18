local function isPlayerChatting()
	return UIS:GetFocusedTextBox() ~= nil
end

local function toggleParryButton()
	parryButtonToggle = not parryButtonToggle
end

local function onKeyPress(input)
	if not isPlayerChatting() and input.KeyCode == Enum.KeyCode[SpamKeybind] then
		toggleParryButton()
	end
end

local function spamRemote()
	if not isPlayerChatting() and parryButtonToggle then
		local currentTime = tick()
		if currentTime - lastFireTime >= spamInterval then
			Parry()
			lastFireTime = currentTime
		end
	end
end

UIS.InputBegan:Connect(onKeyPress)
RS.Heartbeat:Connect(spamRemote)

--// Other

local function ImLagging()
	settings().Rendering.QualityLevel = "Level01"
	for _, v in pairs(game:GetDescendants()) do
		if v:IsA("SpotLight") or
			v:IsA("PointLight") or
			v:IsA("SurfaceLight") or
			v:IsA("ParticleEmitter") or
			v:IsA("Trail") or
			v:IsA("Sparkles") or
			v:IsA("Smoke") or
			v:IsA("Fire") or
			v:IsA("Beam") then
			v.Enabled = false
		end
		if v:IsA("BillboardGui") or
			v:IsA("SurfaceGui") or
			v:IsA("BloomEffect") or
			v:IsA("BlurEffect") or
			v:IsA("ColorCorrectionEffect") or
			v:IsA("DepthOfFieldEffect") or
			v:IsA("SunRaysEffect") or
			v:IsA("Atmosphere") or
			v:IsA("Sky") or
			v:IsA("Clouds") then
			v:Destroy()
		end
		if v:IsA("BasePart") then
			v.Material = Enum.Material.Plastic
		end
		if v:IsA("Decal") or 
			v:IsA("Texture") then
			v:Destroy()
		end
	end
	workspace.Terrain.WaterWaveSpeed = 0
	game.Lighting.GlobalShadows = false
	game.Lighting.ClockTime = 17.5
	game.Lighting.FogEnd = math.huge
	game.Lighting.Brightness = 0.5
end

if Anti_Lag then
	ImLagging()
	Map.ChildAdded:Connect(function()
		wait(2)
		ImLagging()
	end)
end

local function ResetChar(input)
	if not isPlayerChatting() and input.KeyCode == Enum.KeyCode[Reset_Char_Key] then
		Char.Humanoid.Health = 0
	end
end

UIS.InputBegan:Connect(ResetChar)

local function SexyUI()
	local ui = Instance.new("ScreenGui")
	local fpstxt = Instance.new("TextLabel")
	local pingtxt = Instance.new("TextLabel")
	local manual = Instance.new("TextLabel")
	ui.Name = "ui"
	ui.Parent = game:GetService("CoreGui")
	ui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling
	fpstxt.Name = "fpstxt"
	fpstxt.Parent = ui
	fpstxt.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
	fpstxt.BackgroundTransparency = 1.000
	fpstxt.BorderColor3 = Color3.fromRGB(0, 0, 0)
	fpstxt.BorderSizePixel = 0
	fpstxt.Position = UDim2.new(0.914460301, 0, 0.922939062, 0)
	fpstxt.Size = UDim2.new(0.0855397135, 0, 0.0358422957, 0)
	fpstxt.Font = Enum.Font.TitilliumWeb
	fpstxt.Text = "[FPS]"
	fpstxt.TextColor3 = Color3.fromRGB(255, 255, 255)
	fpstxt.TextSize = 20.000
	fpstxt.TextStrokeTransparency = 0.000
	fpstxt.TextXAlignment = Enum.TextXAlignment.Right
	pingtxt.Name = "pingtxt"
	pingtxt.Parent = ui
	pingtxt.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
	pingtxt.BackgroundTransparency = 1.000
	pingtxt.BorderColor3 = Color3.fromRGB(0, 0, 0)
	pingtxt.BorderSizePixel = 0
	pingtxt.Position = UDim2.new(0.914460301, 0, 0.95985657, 0)
	pingtxt.Size = UDim2.new(0.0855397135, 0, 0.0358422957, 0)
	pingtxt.Font = Enum.Font.TitilliumWeb
	pingtxt.Text = "[PING]"
	pingtxt.TextColor3 = Color3.fromRGB(255, 255, 255)
	pingtxt.TextSize = 20.000
	pingtxt.TextStrokeTransparency = 0.000
	pingtxt.TextXAlignment = Enum.TextXAlignment.Right
	manual.Name = "manual"
	manual.Parent = ui
	manual.BackgroundColor3 = Color3.fromRGB(255, 255, 255)
	manual.BackgroundTransparency = 1.000
	manual.BorderColor3 = Color3.fromRGB(0, 0, 0)
	manual.BorderSizePixel = 0
	manual.Position = UDim2.new(0.914460301, 0, 0.887096763, 0)
	manual.Size = UDim2.new(0.0855397135, 0, 0.0358422957, 0)
	manual.Font = Enum.Font.TitilliumWeb
	manual.Text = "[SPAMMING]"
	manual.TextColor3 = Color3.fromRGB(255,0,0)
	manual.TextSize = 20.000
	manual.TextStrokeTransparency = 0.000
	manual.TextXAlignment = Enum.TextXAlignment.Right
	local function update()
		local fps = string.split(game.Stats.Workspace.Heartbeat:GetValueString(), ".")
		local ping = string.split(string.split(game.Stats.Network.ServerStatsItem["Data Ping"]:GetValueString(), " ")[1], ".")
		fpstxt.Text = "[FPS] "..fps[1]
		pingtxt.Text = "[PING] "..ping[1]
		if tonumber(fps[1]) < 40 then
			fpstxt.TextColor3 = Color3.fromRGB(255,0,0)
		elseif tonumber(fps[1]) > 40 then
			fpstxt.TextColor3 = Color3.fromRGB(255,255,255)
		end
		if tonumber(ping[1]) > 200 then
			pingtxt.TextColor3 = Color3.fromRGB(255,0,0)
		elseif tonumber(ping[1]) < 200 then
			pingtxt.TextColor3 = Color3.fromRGB(255,255,255)
		end
	end
	local tog = false
	UIS.InputBegan:Connect(function(input)
		if not isPlayerChatting() and input.KeyCode == Enum.KeyCode[SpamKeybind] then
			if not tog then
				tog = true
				manual.TextColor3 = Color3.fromRGB(0,255,0)
			else
				tog = false
				manual.TextColor3 = Color3.fromRGB(255,0,0)
			end
		end
	end)
	while wait(0.1) do
		update()
	end
end

if Show_UI then
	SexyUI()
end

-- Limited Emote
local function PlayEmote()
	animationTrack:Play()
	game:GetService("ReplicatedStorage").Remotes.CustomEmote:FireServer(true, "Wavelight")
end
local function StopEmote()
	animationTrack:Stop()
	game:GetService("ReplicatedStorage").Remotes.CustomEmote:FireServer(false, "Wavelight")
end
game.Players.LocalPlayer.Character.Humanoid.Running:Connect(function(speed)
	if speed >= 0.3 then
		if sex then
			sex = false
			StopEmote()
			game:GetService("ReplicatedStorage").Remotes.CustomEmote:FireServer(false, "Wavelight")
		end
	end
end)
UIS.InputBegan:Connect(function(input)
	if not isPlayerChatting() and input.KeyCode == Enum.KeyCode.T then
		if not sex then
			PlayEmote()
			sex = true
		else
			StopEmote()
			sex = false
		end
	end
end)

local function ShopGUI(input)
	if not isPlayerChatting() and input.KeyCode == Enum.KeyCode[Open_Shop_Key] then
		if not openedclosed then
			openedclosed = true
			Plr.PlayerGui.UI.Shop.AbilityShop.Enabled = true
		else
			openedclosed = false
			Plr.PlayerGui.UI.Shop.AbilityShop.Enabled = false
		end
	end
end

local function Reconnect(newCharacter)
	Char = newCharacter
	RootPart = Char:WaitForChild("HumanoidRootPart")
	sex = false
	local wat = false
	local a1 = Instance.new("Animation")
	a1.AnimationId = "rbxassetid://14557192252"
	local a2 = game:GetService("Players").LocalPlayer.Character.Humanoid:LoadAnimation(animationInstance)
	local function Start()
		a2:Play()
	end
	local function End()
		a2:Stop()
	end
	Char:WaitForChild("Humanoid").Running:Connect(function(speed)
		if speed >= 0.5 then
			if wat then
				wat = false
				End()
				game:GetService("ReplicatedStorage").Remotes.CustomEmote:FireServer(false, "Wavelight")
			end
		end
	end)
	UIS.InputBegan:Connect(function(input)
		if not isPlayerChatting() and input.KeyCode == Enum.KeyCode.T then
			if not wat then
				Start()
				wat = true
			else
				End()
				wat = false
			end
		end
	end)
end

Plr.CharacterAdded:Connect(Reconnect)
