ans = str(eval(raw_input()))
for i in ans:
	s = ""
	for k in xrange(ord(i)):
		s += '+'
	s += '.>'
	print s