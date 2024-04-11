x, y = gets.split.map { |x| x.to_i }

sum = x.abs + y.abs

if x > 0
	if y > 0
		puts [0, sum, sum, 0].join ' '
	else
		puts [0, -sum, sum, 0].join ' '
	end
else
	if y > 0
		puts [-sum, 0, 0, sum].join ' '
	else
		puts [-sum, 0, 0, -sum].join ' '
	end
end