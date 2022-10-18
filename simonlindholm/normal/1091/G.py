import random
import math
import time
import sys

n = int(input())

factors = [n]

t = time.time()
que = 0
while time.time() - t < 4 and que < 90:
    x = random.randrange(0, n)
    if math.gcd(x, n) == 1:
        x2 = x * x % n # print('*', x, x)
        que += 1
        # x2 = int(input())
        print('sqrt', x2)
        sys.stdout.flush()
        y = int(input())
        assert y != -1
        dif = x - y
        if dif < 0:
            dif = -dif
    else:
        dif = x
    factors2 = []
    for f in factors:
        blah = math.gcd(f, dif)
        if blah != 1 and blah != f:
            factors2.append(blah)
            factors2.append(f // blah)
        else:
            factors2.append(f)
    factors = factors2

print('!', len(factors), *factors)
sys.stdout.flush()