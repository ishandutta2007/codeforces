import random
import sys

def gcd(x, y):
    while y:
        t = x % y
        x = y
        y = t
    return x

n = int(raw_input())
candidates = []
factors = []
for i in range(30):
    x = random.randint(1, n - 1)
    y = x * x % n
    print "sqrt " + str(y)
    sys.stdout.flush()
    y = int(raw_input())
    if x != y:
        if x > y:
            x, y = y, x
        candidates.append(y - x)

def divide(n):
    for d in candidates:
        g = gcd(n, d)
        if g != 1 and g != n:
            divide(g)
            divide(n / g)
            return
    factors.append(n)

divide(n)
answer = "! " + str(len(factors))
for x in factors:
    answer += " " + str(x)
print answer