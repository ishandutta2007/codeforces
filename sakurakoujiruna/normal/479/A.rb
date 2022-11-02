a = gets.to_i
b = gets.to_i
c = gets.to_i

ans = [a + b + c, a + b * c, a * b + c,
	(a + b) * c, a * (b + c), a * b * c].max
puts ans