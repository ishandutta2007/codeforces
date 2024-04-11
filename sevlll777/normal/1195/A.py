n, k = map(int, input().split())
g = {}
for i in range(n):
    x = int(input())
    if x not in g:
        g[x] = 0
    g[x] += 1
ans = 0
nap = 0
for u in g:
    ans += g[u] - g[u] % 2
    nap += g[u] // 2
print(min(n, ans + ((n + 1) // 2 - nap)))