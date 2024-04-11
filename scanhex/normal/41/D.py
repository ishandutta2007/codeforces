def restore_path(i, j):
    vi, vj, vmod = i, j, 0
    ans = []
    while prev[vi][vj][vmod] is not None:
        if prev[vi][vj][vmod][1] == vj - 1:
            ans.append('L')
        else:
            ans.append('R')
        vi, vj, vmod = prev[vi][vj][vmod]
    return ''.join(ans)


n, m, k = [int(i) for i in input().split()]
k += 1
a = [[int(i) for i in input()] for i in range(n)]
d = [[[float('-inf')] * k for i in range(m)] for i in range(n)]
prev = [[[None] * k for i in range(m)] for i in range(n)]
for i in range(m):
    d[0][i][a[0][i] % k] = a[0][i]
for i in range(1, n):
    for j in range(m):
        for mod in range(k):
            if j > 0 and d[i - 1][j - 1][(mod + 10 * k - a[i][j]) % k] + a[i][j] > d[i][j][mod]:
                d[i][j][mod] = d[i - 1][j - 1][(mod + 10 * k - a[i][j]) % k] + a[i][j]
                prev[i][j][mod] = (i - 1, j - 1, (mod + 10 * k - a[i][j]) % k)
            if j < m - 1 and d[i - 1][j + 1][(mod + 10 * k - a[i][j]) % k] + a[i][j] > d[i][j][mod]:
                d[i][j][mod] = d[i - 1][j + 1][(mod + 10 * k - a[i][j]) % k] + a[i][j]
                prev[i][j][mod] = (i - 1, j + 1, (mod + 10 * k - a[i][j]) % k)
maxx = max(d[n - 1], key=lambda x: x[0])
if maxx[0] == float('-inf'):
    print(-1)
else:
    print(maxx[0])
    print(d[n - 1].index(maxx) + 1)
    print(restore_path(n - 1, d[n - 1].index(maxx)))