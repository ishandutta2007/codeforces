n = int(raw_input())
ans = False
for i in xrange(n):
	a = map(int, raw_input().split()[1:])
	if 2400 <= a[0] < a[1]:
		ans = True
print 'YES' if ans else 'NO'