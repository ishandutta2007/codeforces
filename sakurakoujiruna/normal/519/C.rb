a, b = gets.split.map { |x| x.to_i }
ans = 0
0.upto(a) do |i|
	if b >= 2 * i
		ans = [ans, i + [(a - i) / 2, b - 2 * i].min].max
	end
end
puts ans