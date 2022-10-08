s = str(eval(raw_input()))
now = 0
t = ""
for i in s:
	p = ord(i)
	if p > now:
		for j in xrange(p-now):
			t += "+"
	else:
		for j in xrange(now-p):
			t += "-"
	now = p
	t += "."
print t