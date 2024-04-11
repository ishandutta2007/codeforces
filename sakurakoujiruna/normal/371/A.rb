n, k = gets.split.map { |x| x.to_i }
a = gets.split.map { |x| x.to_i }

ans = 0
0.upto(k) do |i|
	b = a.select.with_index { |x, j| j % k == i }
	ans += [b.count(1), b.count(2)].min
end
puts ans