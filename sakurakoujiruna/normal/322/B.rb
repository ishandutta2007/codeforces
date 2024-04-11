r, g, b = gets.split.map { |x| x.to_i }

ans = 0
0.upto([r, g, b, 2].min) do |i|
	ans = [ans, i + (r - i) / 3 + (g - i) / 3 + (b - i) / 3].max
end
puts ans