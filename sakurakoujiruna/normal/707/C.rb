n = gets.to_i

if n == 1 or n == 2
	puts -1
elsif n.odd?
	u = n
	v = 1
	puts [(u ** 2 - v ** 2) / 2, (u ** 2 + v ** 2) / 2].join ' '
else
	u = n / 2
	v = 1
	puts [u ** 2 - v ** 2, u ** 2 + v ** 2].join ' '
end