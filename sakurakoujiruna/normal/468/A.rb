n = gets.to_i

if n < 4
	puts 'NO'
else
	puts 'YES'
	if n.even?
		puts '1 * 2 = 2'
		puts '2 * 3 = 6'
		puts '6 * 4 = 24'
		5.upto(n) do |i|
			if i.odd?
				puts (i + 1).to_s + ' - ' + i.to_s + ' = 1'
				puts '24 * 1 = 24'
			end
		end
	else
		puts '5 - 1 = 4'
		puts '4 - 2 = 2'
		puts '2 * 3 = 6'
		puts '6 * 4 = 24'
		6.upto(n) do |i|
			if i.even?
				puts (i + 1).to_s + ' - ' + i.to_s + ' = 1'
				puts '24 * 1 = 24'
			end
		end
	end
end