t = int(input())
for t in range(t):
	input()
	m, n = list(map(int, input().split()))
	a = [[0] * n for i in range(m)]
	for i in range(m):
		a[i] = list(map(int, input().split()))

	def chk(x):

		ok = 1
		c = [0] * m
		for j in range(n):
			tmp = 0
			for i in range(m):
				if a[i][j] >= x:
					c[i] += 1
					tmp = 1
			
			if tmp == 0:
				ok = 0

		if ok and max(c) >= 2:
			return 1
		return 0

	l = 0; r = 1000000000 + 1;
	while r - l > 1:
		mid = (l+r)>>1
		if chk(mid):
			l = mid
		else:
			r = mid
	print(l)