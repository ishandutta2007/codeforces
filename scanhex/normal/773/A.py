def xgcd(a, b):
    if b == 0:
        return 1, 0
    x1, y1 = xgcd(b, a % b)
    return y1, x1 - (a // b) * y1

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

t = int(input())
for kek in range(t):
    x, y, p, q = map(int, input().split())
    if p == 0:
        if x == 0:
            print(0)
        else:
            print(-1)
        continue
    if p == q:
        if x == y:
            print(0)
        else:
            print(-1)
        continue

    v = p * y - q * x
    g = gcd(q - p, p)
    k0, l0 = xgcd(q - p, p)
    l0 *= -1
    g1 = v // g
    k0 *= g1
    l0 *= g1

    xx = (-k0 + p - 1) // p
    
    xx = max(xx, (-l0 + q - p - 1) // (q - p))
    
    l = l0 + xx * (q - p)
    k = k0 + xx * p;

    print(k + l)