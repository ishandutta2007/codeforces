n, m, k, x, y = map(int, input().split())
if n != 1:
    oh = 2 * n * m - 2 * m
else:
    oh = m
gar_pls = k // oh
k %= oh
Q = [([0] * (m + 1)) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        if n > i > 1:
            Q[i][j] = gar_pls * 2
        else:
            Q[i][j] = gar_pls
        if k:
            Q[i][j] += 1
            k -= 1
for i in range(n - 1, 1, -1):
    for j in range(1, m + 1):
        if k:
            Q[i][j] += 1
            k -= 1
mn = 10 ** 40
mx = -10 ** 40
serega = Q[x][y]
for i in Q[1:]:
    for j in i[1:]:
        mn = min(mn, j)
        mx = max(mx, j)
print(mx, mn, serega)