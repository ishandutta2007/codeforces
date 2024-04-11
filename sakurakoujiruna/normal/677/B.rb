n, h, k = gets.split.map { |x| x.to_i }
a = gets.split.map { |x| x.to_i }

ans = 0
sum = 0
a.each do |now|
	cut = [(now - (h - sum) + k - 1) / k, 0].max
	ans += cut
	sum = [sum - cut * k, 0].max
	sum += now
end
ans += (sum + k - 1) / k
puts ans