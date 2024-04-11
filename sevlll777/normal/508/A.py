n, m, k = map(int, input().split())
A = [([0] * (m + 2)) for _ in range(2 + n)]
for iy in range(k):
    a, b = map(int, input().split())
    A[a][b] = 1
    q = A[a - 1][b - 1]
    w = A[a - 1][b]
    e = A[a - 1][b + 1]
    r = A[a][b - 1]
    t = A[a][b + 1]
    y = A[a + 1][b - 1]
    u = A[a + 1][b]
    i = A[a + 1][b + 1]
    if q == w == r == 1 or w == e == t == 1 or t == u == i == 1 or r == y == u == 1:
        print(iy + 1)
        exit(0)
print(0)