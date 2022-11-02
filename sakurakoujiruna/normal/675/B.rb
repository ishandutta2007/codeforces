n, a, b, c, d = gets.split.map { |x| x.to_i }

sum = [a + b, b + d, d + c, c + a]

cnt = 0
1.upto(n) do |i|
	flag = true
	1.upto(3) do |j|
		t = i + sum[0] - sum[j]
		flag = false unless t.between? 1, n
	end
	cnt += 1 if flag
end
puts cnt * n