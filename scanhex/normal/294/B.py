n = int(input())
t, w = [], []
for i in range(n):
    a, b = map(int, input().split())
    t.append(a)
    w.append(b)
d = [[float('-inf')] * (2 * n + 1) for i in range(n + 1)]
d[0][0] = 0
for i in range(n):
    for j in range(2 * n + 1):
        if j + t[i] <= 2 * n:
            d[i + 1][j + t[i]] = max(d[i + 1][j + t[i]], d[i][j] + w[i])
        d[i + 1][j] = max(d[i + 1][j], d[i][j])
for j in range(2 * n + 1):
    if sum(w) - d[n][j] <= j:
        print(j)
        exit(0)