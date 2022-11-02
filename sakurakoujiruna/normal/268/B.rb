n = gets.to_i
ans = n
n.times do |i|
	ans += (i + 1) * (n - i - 1)
end
puts ans