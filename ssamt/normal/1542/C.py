def gcd(a, b):
    if a < 0:
        return gcd(-a, b)
    if b < 0:
        return gcd(a, -b)
    if a > b:
        return gcd(b, a)
    if a == 0:
        return b
    return gcd(b%a, a)

mod = 10**9+7
t = int(input())
for i in range(t):
    n = int(input())
    g = 1
    answer = n%mod
    j = 1
    while g <= n:
        j += 1
        answer = (answer+n//g)%mod
        g = g*j//gcd(g, j)
    print(answer)