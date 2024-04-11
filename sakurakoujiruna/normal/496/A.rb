n = gets.to_i
a = gets.split.map { |x| x.to_i }

ans = 2333
1.upto(n - 2) do |i|
	b = a[0, i] + a[i + 1, n - i - 1]
	tmp = 0
	0.upto(n - 3) do |j|
		tmp = [tmp, b[j + 1] - b[j]].max
	end
	ans = [ans, tmp].min
end
puts ans