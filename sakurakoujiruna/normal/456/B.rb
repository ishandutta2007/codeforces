n = ('00' + gets.chomp)[-2, 2].to_i

if n % 4 == 0
	puts 4
else
	puts 0
end