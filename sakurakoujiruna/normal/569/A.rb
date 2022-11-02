t, s, q = gets.split.map { |x| x.to_i }

ans = 0
while s < t
	s *= q
	ans += 1
end
puts ans