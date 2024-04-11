from collections import deque

q = int(input())
while q:
	q -= 1
	input()
	n, k = map(int, input().split())
	x = list(map(lambda x : int(x) - 1, input().split()))
	g = [[] for u in range(n)]
	for i in range(n - 1):
		u, v = map(lambda x : int(x) - 1, input().split())
		g[u].append(v)
		g[v].append(u)
	d = [-1 for u in range(n)]
	d[0] = 0
	que = deque()
	que.append(0)
	while que:
		u = que.popleft()
		for v in g[u]:
			if d[v] == -1:
				d[v] = d[u] + 1
				que.append(v)
	e = [-1 for u in range(n)]
	for u in x:
		e[u] = 0
		que.append(u)
	while que:
		u = que.popleft()
		for v in g[u]:
			if e[v] == -1:
				e[v] = e[u] + 1
				que.append(v)
	f = False
	for u in range(1, n):
		if len(g[u]) == 1 and d[u] < e[u]:
			f = True
	if f:
		print("YES")
	else:
		print("NO")