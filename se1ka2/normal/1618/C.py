from functools import reduce

def gcd(n, m):
	if m == 0:
		return n
	return gcd(m, n % m)

t = int(input())
while t:
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	g = reduce(gcd, a[::2])
	if all([a[i] % g for i in range(1, n, 2)]):
		print(g)
		continue
	g = reduce(gcd, a[1::2])
	if all([a[i] % g for i in range(0, n, 2)]):
		print(g)
		continue
	print(0)