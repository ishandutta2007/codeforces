import sys
n, m = map(int, sys.stdin.readline().strip().split())
g = []
for i in xrange(n):
    g.append([])

for i in xrange(m):
    a, b = map(lambda x: int(x) - 1, sys.stdin.readline().strip().split())
    g[a].append(b)
    g[b].append(a)

def bfs(s):
    q = [s]
    u = [False] * n
    d = [0] * n
    paths = [0] * n
    paths[s] = 1
    u[s] = True

    while q:
        x, q = q[0], q[1:]
        for y in g[x]:
            if not u[y]:
                u[y] = True
                d[y] = d[x] + 1
                q.append(y)

            if d[y] == d[x] + 1:
                paths[y] = paths[y] + paths[x]

    return d, paths


d, paths = bfs(0)
db, pathsb = bfs(n-1)

length = d[n-1]
total = paths[n-1]

best = 0
for x in xrange(n):
    cur = 0
    for y in g[x]:
        if d[x] + db[y] + 1 == length: cur += paths[x] * pathsb[y]
        if d[y] + db[x] + 1 == length: cur += paths[y] * pathsb[x]

    if cur > best: best = cur

print best * 1.0 / total