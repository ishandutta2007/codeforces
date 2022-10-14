n, m = map(int, input().split())
gr = {i:set() for i in range(n)}
for _ in range(m):
    a, b = map(int, input().split())
    a-=1;
    b-=1
    gr[a].add(b)
    gr[b].add(a)
used=set()
ans = 1
for v in range(n):
    if v not in used:
        c = 0
        q = [v]
        used.add(v)
        while q:
            u = q.pop()
            for uu in gr[u]:
                if uu not in used:
                    q.append(uu)
                    used.add(uu)
                    c += 1
        ans *= 2 ** c

print(ans)