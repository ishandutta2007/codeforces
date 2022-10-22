def gcd(n, m):
	if m == 0:
		return n
	return gcd(m, n % m)

t = int(input())
while t:
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	b = [abs(a[i + 1] - a[i]) for i in range(n - 1)]
	g = 0
	for x in b:
		g = gcd(g, x)
	if g == 0:
		print(-1)
	else:
		print(g)