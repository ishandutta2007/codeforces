a, b = gets.split.map { |x| x.to_i }

ans = 0
while b != 0
	ans += a / b
	a -= a / b * b
	a, b = b, a
end

puts ans