import random
import math

n = int(input())
z = [n]

for i in range(15):
    w = random.randint(1, n - 1)
    print('sqrt', w * w % n)
    v = int(input())

    y = []
    for x in z:
        y.append(math.gcd(w+v, x))
        y.append(x // y[-1])
    z = y

z = list(set(z) - {1})
print('!', len(z), *z)