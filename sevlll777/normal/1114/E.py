from random import randint
from math import gcd
n = int(input())
l = 0
r = 10 ** 9 + 1
while r - l > 1:
    m = (l + r) // 2
    print('>', m)
    ans = int(input())
    if ans:
        l = m
    else:
        r = m
f = l + 1
E = []
for _ in range(30):
    print('?', randint(1, n))
    ay = int(input())
    E.append(ay)
E.sort()
g = E[1] - E[0]
for i in range(1, 30):
    g = gcd(g, E[i] - E[i - 1])
print('!', f - (n - 1) * g, g)
####