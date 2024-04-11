from math import gcd


def lcm(a, b): return a * b // gcd(a, b)


for _ in range(int(input())):
    n = int(input())
    P = list(map(int, input().split()))
    x, a = map(int, input().split())
    y, b = map(int, input().split())
    k = int(input())
    P.sort(reverse=True)
    l = 0
    r = n + 1
    while r - l > 1:
        m = (l + r) // 2
        g1 = m // lcm(a, b)
        g2 = m // a - g1
        g3 = m // b - g1
        cnt = 0
        for i in range(g1):
            cnt += (x + y) * P[i] // 100
        if x > y:
            for i in range(g1, g1 + g2):
                cnt += x * P[i] // 100
            for i in range(g1 + g2, g1 + g2 + g3):
                cnt += y * P[i] // 100
        else:
            for i in range(g1, g1 + g3):
                cnt += y * P[i] // 100
            for i in range(g1 + g3, g1 + g2 + g3):
                cnt += x * P[i] // 100
        if cnt >= k:
            r = m
        else:
            l = m
    if l == n:
        print(-1)
    else:
        print(l + 1)