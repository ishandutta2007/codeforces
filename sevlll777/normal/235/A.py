from math import gcd

def lcm(a, b):
    return a * b // gcd(a, b)


n  =int(input())
if n == 1:
    print(1)
elif n == 2:
    print(2)
else:
    ans = 0
    for b1 in range(min(n, 100)):
        for b2 in range(min(n, 100)):
            for b3 in range(min(n, 100)):
                ans = max(ans, lcm(lcm(n-b1,n-b2),n-b3))
    print(ans)