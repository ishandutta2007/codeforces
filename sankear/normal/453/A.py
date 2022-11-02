m, n = raw_input().split()
m = int(m)
n = int(n)

ans = 0
for i in xrange(1, m + 1):
	q = 1.0 * (i - 1) / i
	ans += ((1.0 * i / m) ** n) * ((q ** n) - 1) / (q - 1)

print ans