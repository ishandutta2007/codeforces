M = 10 ** 9 + 7
n, l, r = map(int, input().split())
p0 = r // 3 - (l - 1) // 3
p1 = (r - 1) // 3 - (l - 2) // 3
p2 = (r - 2) // 3 - (l - 3) // 3
d0, d1, d2 = 1, 0, 0
for _ in range(n):
    d00 = (d0 * p0) + (d1 * p2) + (d2 * p1)
    d11 = (d0 * p1) + (d1 * p0) + (d2 * p2)
    d22 = (d0 * p2) + (d1 * p1) + (d2 * p0)
    d00 %= M
    d11 %= M
    d22 %= M
    d0, d1, d2 = d00, d11, d22
print(d0)