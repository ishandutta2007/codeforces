from math import gcd
n, m, q = map(int, input().split())
d = gcd(n, m)
x = n // d
y = m // d
for _ in range(q):
    sx, sy, ex, ey = map(int, input().split())
    p1 = 0
    p2 = 0
    if sx == 1:
        p1 = (sy - 1) // x
    else:
        p1 = (sy - 1) // y
    if ex == 1:
        p2 = (ey - 1) // x
    else:
        p2 = (ey - 1) // y
    if p1 == p2:
        print('YES')
    else:
        print('NO')