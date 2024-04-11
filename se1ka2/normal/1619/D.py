t = int(input())
while t:
	t -= 1
	input()
	m, n = map(int, input().split())
	p = [[] for i in range(m)]
	for i in range(m):
		p[i] = list(map(int, input().split()))
	left, right = -1, 1000000002
	while right - left > 1:
		mid = (right + left) // 2
		f = False
		b = [False for j in range(n)]
		for i in range(m):
			c = 0
			for j in range(n):
				if p[i][j] >= mid:
					c += 1
					b[j] = True
			if c >= 2:
				f = True
		if all(b) and f:
			left = mid
		else:
			right = mid
	print(left)