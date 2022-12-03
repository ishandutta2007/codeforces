n, t = gets.split.map(&:to_i)
if n == 1
	if t == 10
		puts -1
	else
		puts t
	end
else
	x = 10**(n - 1)
	x += 1 until x % t == 0
	puts x
end