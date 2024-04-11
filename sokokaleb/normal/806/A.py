import sys
t = int(input())

def ex_gcd(a, b):
    if b == 0: return (a, 1, 0)
    gcd, u, v = ex_gcd(b, a % b)
    return gcd, v, u - (a // b) * v

for tc in range(t):
    x, y, p, q = map(int, input().split())
    c = y * p - x * q
    gcd, u, v = ex_gcd(q, -p)
    if (p * y == q * x):
        sys.stdout.write('0\n')
    elif c % gcd != 0 or (p == 0 and x != 0) or (p // q == 1 and x // y != 1):
        sys.stdout.write('-1\n')
    else:
        u *= c // gcd
        v *= c // gcd

        gerak_u = -p // gcd
        gerak_v = q // gcd
        if gerak_u > 0:
            gerak_u, gerak_v = -gerak_u, -gerak_v
        elif gerak_u == 0:
            gerak_v = abs(gerak_v)
        if u != 0:
            jarak = u // gerak_u
            u -= jarak * gerak_u
            v += jarak * gerak_v
        if u < 0:
            u -= gerak_u
            v += gerak_v


        if u <= v:
            sys.stdout.write('{}\n'.format(v))
        else:
            # gerak_u negatip
            if -gerak_u >= gerak_v:
                sys.stdout.write('-1\n')
            else:
                lol = gerak_v + gerak_u
                lil = u - v
                ans = (lil + lol - 1) // (lol)
                b = v + ans * gerak_v
                sys.stdout.write('{}\n'.format(b))