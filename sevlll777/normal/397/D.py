from math import gcd


def prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


for i in range(int(input())):
    n = int(input())
    x = n
    y = n + 1
    while not prime(x):
        x -= 1
    while not prime(y):
        y += 1
    p = 2 * n - 2 * x + 2 + y * x - 2 * y
    q = 2 * y * x
    d = gcd(p, q)
    p //= d
    q //= d
    print(str(p) + '/' + str(q))