from heapq import heappop, heappush
from collections import deque
inf = 1 << 60

n, m = map(int, input().split())

G = [[] for _ in range(n)]
Q = []
dist = {}
prev = {}

for _ in range(m):
	a, b, c = map(int, input().split())
	a -= 1
	b -= 1
	G[a].append((b, c))
	G[b].append((a, c))
	
dist[0] = 0
heappush(Q, (dist[0], 0))

while Q:
	d, v = heappop(Q)

	if d != dist[v]:
		continue

	for u, w in G[v]:
		curr_dist = d + w
		if dist.get(u, inf) > curr_dist:
			dist[u] = curr_dist
			prev[u] = v
			heappush(Q, (curr_dist, u))

if n-1 not in dist:
	print(-1)
	exit(0)

d = deque([n])
curr = n-1

while curr:
	curr = prev[curr]
	d.appendleft(curr + 1)

print(*d)