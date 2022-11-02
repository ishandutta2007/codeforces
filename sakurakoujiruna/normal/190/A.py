n, m = [int(x) for x in raw_input().split()]

if n == 0 and m == 0 :
	print '0 0'
elif n == 0 :
	print 'Impossible'
else :
	ans = [n + m - min(n, m), n + m - min(1, m)]
	print ' '.join([str(x) for x in ans])