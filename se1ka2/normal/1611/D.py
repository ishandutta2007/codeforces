q = int(input())
while q:
	q -= 1
	n = int(input())
	r = -1
	t = [[] for u in range(n)]
	b = list(map(lambda x : int(x) - 1, input().split()))
	for u in range(n):
		if b[u] == u:
			r = u
		t[b[u]].append(u)
	c = [False for u in range(n)]
	c[r] = True
	p = list(map(lambda x : int(x) - 1, input().split()))
	e = [0 for u in range(n)]
	w = [0 for u in range(n)]
	f = True
	for i in range(n):
		e[p[i]] = i
		if not c[p[i]]:
			f = False
			break;
		w[p[i]] = i - e[b[p[i]]]
		for u in t[p[i]]:
			c[u] = True
	if not f:
		print(-1)
	else:
		print(*w)