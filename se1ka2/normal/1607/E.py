t = int(input())
while t:
	t -= 1
	n, m = map(int, input().split())
	s = input()
	l = 0
	r = 0
	d = 0
	u = 0
	x = 0
	y = 0
	dx = {'L' : 0, 'R' : 0, 'D' : 1, 'U' : -1}
	dy = {'L' : -1, 'R' : 1, 'D' : 0, 'U' : 0}
	for i in range(len(s) + 1):
		if i == len(s):
			print(-u + 1, -l + 1)
			break;
		x += dx[s[i]]
		y += dy[s[i]]
		d = max(d, x)
		if d - u >= n:
			print(-u + 1, -l + 1)
			break
		u = min(u, x)
		if d - u >= n:
			print(-u, -l + 1)
			break
		l = min(l, y)
		if r - l >= m:
			print(-u + 1, -l)
			break
		r = max(r, y)
		if r - l >= m:
			print(-u + 1, -l + 1)
			break