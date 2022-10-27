t = int(input())

for test in range(t):

	n, m, k = list(map(int, input().split()))

	cnt = ((n + m - 1) // m) * (n % m)

	now = 1
	for i in range(k):

		for j in range(n % m):
			print((n + m - 1) // m, end = ' ')
			for x in range((n + m - 1) // m):
				print(now, end = ' ')
				now += 1
				if now == n + 1: now = 1
			print()
		tmp = now
		for j in range(m - (n % m)):
			print(n // m, end = ' ')
			for x in range(n // m):
				print(now, end = ' ')
				now += 1
				if now == n + 1: now = 1
		now = tmp
		print()