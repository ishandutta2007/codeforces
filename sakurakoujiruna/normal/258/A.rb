s = gets.chomp
if s.count('0') == 0
	puts s.chop
else
	id = s.index '0'
	s[id] = ''
	puts s
end