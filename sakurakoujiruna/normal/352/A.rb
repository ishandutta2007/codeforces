n = gets.to_i
a = gets.split.map { |x| x.to_i }

c0 = a.count 0
c5 = a.count 5

if c0 == 0
	puts -1
elsif c5 < 9
	puts 0
else
	puts '5' * (c5 / 9 * 9) + '0' * c0
end