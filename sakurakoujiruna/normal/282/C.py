a = raw_input()
b = raw_input()

if len(a) != len(b) :
	print 'NO'
elif (a.count('1') > 0) ^ (b.count('1') > 0) :
	print 'NO'
else :
	print 'YES'