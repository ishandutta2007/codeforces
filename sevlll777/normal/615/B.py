n, m = map(int, input().split())
gr = {o:set() for o in range(n)}
for _ in range(m):
    a, b = map(int, input().split())
    a-=1
    b-=1
    gr[a].add(b)
    gr[b].add(a)
d = [1] * n
for v in range(n):
    for u in gr[v]:
        if u < v:
            d[v] = max(d[v], 1 + d[u])
ans = 0
for v in range(n):
    ans = max(ans, len(gr[v]) * d[v])
print(ans)