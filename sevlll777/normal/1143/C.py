n = int(input())
par = {}
chi = {i: 0 for i in range(1, n + 1)}
fl = 0
uvaj = {}
for i in range(n):
    p, c = map(int, input().split())
    if p != -1:
        par[i + 1] = p
        chi[p] += 1 - c
    uvaj[i + 1] = 1 - c
for i in range(1, n + 1):
    g = chi[i]
    if g == 0 and uvaj[i] == 0:
        print(i, end=' ')
        fl = 1
if fl == 0:
    print(-1)