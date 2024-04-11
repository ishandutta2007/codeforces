n = gets.to_i
a = gets.split.map { |x| x.to_i }

sum = a.reduce(:+)
if sum % n == 0
	puts n
else
	puts n - 1
end