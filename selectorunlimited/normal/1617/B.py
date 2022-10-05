import math

def findD(n):
    d = 1
    while d * d <= n:
        if n % d == 0:
            return d
        d += 1
    return n

def findA(n):
    a = 1
    while a < n:
        a += 1
        if math.gcd(a, n - a) == 1:
            return a

for t in range(int(input())):
    n = int(input())
    d = findD(n)
    a = findA(n - d)
    print(a, n - a - d, d)