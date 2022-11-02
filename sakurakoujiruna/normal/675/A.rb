a, b, c = gets.split.map { |x| x.to_i }

flag = false
if c == 0
	flag = true if a == b
elsif (b - a) % c == 0 and (b - a) / c >= 0
	flag = true
end

if flag
	puts 'YES'
else
	puts 'NO'
end