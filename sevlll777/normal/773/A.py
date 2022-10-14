from math import ceil
for _ in range(int(input())):
    x, y, p, q = map(int, input().split())
    if p == q and x != y:
        print(-1)
    elif p == q:
        print(0)
    elif p == 0 and x == 0:
        print(0)
    elif p == 0:
        print(-1)
    else:
        a = y // q
        r = y % q
        g1 = (x - p * a + p - 1) // p
        g2 = ceil((x - r - p * a) / (p - q))
        print(max(g1, g2) * q - r)