n, m = gets.split.map { |x| x.to_i }
if n == 1
	puts 1
elsif m == 1
	puts 2
elsif m == n
	puts n - 1
else
	if m - 1 >= n - m
		puts m - 1
	else
		puts m + 1
	end
end