w, m = [int(s) for s in raw_input().split()]

t = 1
for i in range(101) :
	if m % (t * w) / t == 1 :
		m -= t
	elif m % (t * w) / t == w - 1 :
		m += t
	t = t * w

if m == 0 :
	print 'YES'
else :
	print 'NO'