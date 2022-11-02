t, s, x = gets.split.map { |x| x.to_i }

if x >= t and (x - t) % s == 0
	puts 'YES'
elsif x >= t + s + 1 and (x - t - 1) % s == 0
	puts 'YES'
else
	puts 'NO'
end