def f n
	return n / 2 if n.even?
	f(n - 1) - n
end

n = gets.to_i
puts f(n)