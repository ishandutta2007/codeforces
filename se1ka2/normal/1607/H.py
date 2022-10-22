t = int(input())
d = [[] for i in range(2000001)]
while t:
	t -= 1
	input()
	n = int(input())
	v = [0 for i in range(n)]
	a = [0 for i in range(n)]
	b = [0 for i in range(n)]
	m = [0 for i in range(n)]
	for i in range(n):
		a[i], b[i], m[i] = map(int, input().split())
		l = a[i] - m[i]
		r = a[i]
		if a[i] - m[i] < 0:
			l = 0
		if b[i] - m[i] < 0:
			r = a[i] - (m[i] - b[i])
		d[a[i] + b[i] - m[i]].append((r, l, i))
		v.append(a[i] + b[i] - m[i])
	ans = 0
	e = [0 for i in range(n)]
	for x in v:
		if not d[x]:
			continue
		d[x].sort()
		last = -1
		for (r, l, i) in d[x]:
			if l > last:
				last = r
				ans += 1
			e[i] = a[i] - last
		d[x] = []
	print(ans)
	for i in range(n):
		print(e[i], m[i] - e[i])