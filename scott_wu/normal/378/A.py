import math

a, b = (int(s) for s in raw_input().split())

x, y, z = 0, 0, 0
for i in range(1, 7):
    m, n = math.fabs (a - i), math.fabs (b - i)
    if m > n:
        z += 1
    elif m == n:
        y += 1
    else:
        x += 1

print " ".join(map(str, (x, y, z)))