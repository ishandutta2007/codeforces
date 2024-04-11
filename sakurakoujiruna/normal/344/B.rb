a, b, c = gets.split.map { |x| x.to_i }

if (a + b + c).odd?
	puts 'Impossible'
else
	sum = (a + b + c) / 2
	x, y, z = sum - c, sum - a, sum - b
	if x < 0 or y < 0 or z < 0
		puts 'Impossible'
	else
		puts [x, y, z].join ' '
	end
end