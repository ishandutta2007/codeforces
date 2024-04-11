from collections import deque 

q = int(input())
while q:
	q -= 1
	input()
	n, k = map(int, input().split())
	g = [[] for u in range(n)]
	e = [0 for u in range(n)]
	for i in range(n - 1):
		u, v = map(lambda x : int(x) - 1, input().split())
		g[u].append(v)
		g[v].append(u)
		e[u] += 1
		e[v] += 1
	que = deque()
	d = [-1 for u in range(n)]
	for u in range(n):
		if e[u] == 1:
			e[u] = 0
			d[u] = 0
			que.append(u)
	while que:
		u = que.popleft()
		for v in g[u]:
			e[v] -= 1
			if e[v] == 1:
				d[v] = d[u] + 1
				e[v] = 0
				que.append(v)
	ans = 0
	for u in range(n):
		if d[u] >= k:
			ans += 1
	print(ans)