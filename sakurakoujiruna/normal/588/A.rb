n = gets.to_i

last_min = 0x3f3f3f3f

ans = 0
n.times do
	a, p = gets.split.map { |s| s.to_i }
	last_min = [last_min, p].min
	ans += last_min * a
end

puts ans