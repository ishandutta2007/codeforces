Mod = (1e9 + 7).to_i

n = gets.to_i

ans1 = 1
ans2 = 1

n.times do
	ans1 *= 27
	ans2 *= 7

	ans1 %= Mod
	ans2 %= Mod
end

ans = (ans1 - ans2 + Mod) % Mod
puts ans