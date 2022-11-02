n = gets.to_i
ans = 0
n.times do
	x1, y1, x2, y2 = gets.split.map { |x| x.to_i }
	ans += (x2 - x1 + 1) * (y2 - y1 + 1)
end
puts ans