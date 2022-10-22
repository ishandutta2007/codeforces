import bisect

t = int(input())
while t:
	t -= 1
	n, s = map(int, input().split())
	a = list(map(int, input().split()))
	l, r = 0, 0
	x = 0
	d = 0
	ans = (-1, -1)
	while r < n:
		x -= a[r]
		r += 1
		while x > s:
			x += a[l]
			l += 1
		if r - l > d:
			d = r - l
			ans = (l + 1, r)
	if d:
		print(*ans)
	else:
		print(-1)