t = int(input())
while t:
	t -= 1
	n, m, k = map(int, input().split())
	d = n % m
	e = n // m
	r = 0
	for _ in range(k):
		for i in range(d):
			x = [(r + i * (e + 1) + j) % n + 1 for j in range(e + 1)]
			print(e + 1, end = " ")
			print(*x)
		r = (r + d * (e + 1)) % n
		for i in range(m - d):
			x = [(r + i * e + j) % n + 1 for j in range(e)]
			print(e, end = " ")
			print(*x)
	print()