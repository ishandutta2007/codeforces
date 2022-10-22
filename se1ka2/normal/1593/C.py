t = int(input())
while t:
	t -= 1
	n, k = map(int, input().split())
	x = list(map(int, input().split()))
	x = list(map(lambda y : n - y, x))
	x.sort()
	c = 0;
	for i in range(k):
		if x[i] < n:
			n -= x[i]
		else:
			break
		c = i + 1
	print(c)