n = gets.to_i
if n.odd?
	puts [9, n - 9].join ' '
else
	puts [4, n - 4].join ' '
end