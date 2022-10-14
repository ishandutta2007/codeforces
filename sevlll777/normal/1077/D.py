n, k = map(int, input().split())
S = list(map(int, input().split()))
g = {}
for i in S:
    if i not in g:
        g[i] = 0
    g[i] += 1
l = 0
r = 10 ** 7
realans = S
while r - l > 1:
    m = (l + r) // 2
    cnt = 0
    ans = []
    for i in g:
        cnt += g[i] // m
        for _ in range(g[i] // m):
            ans.append(i)
    if cnt >= k:
        realans = ans
        l = m
    else:
        r = m
print(' '.join(list(map(str, realans[:k]))))