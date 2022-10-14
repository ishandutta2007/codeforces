from bisect import *
n, d = map(int, input().split())
lol = []
for _ in range(n):
    m, s = map(int, input().split())
    lol.append((m, s))
lol.sort()
pre = [0]
for c in lol:
    pre.append(pre[-1] + c[1])
ans = 0
for i in range(n):
    j = lol[i]
    b2 = bisect_right(lol, (j[0] + d - 1, 10**100))
    ans = max(ans, pre[b2]-pre[i])

print(ans)