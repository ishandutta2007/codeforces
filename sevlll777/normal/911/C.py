from math import gcd


def lcm(a, b):
    return a * b // gcd(a, b)


def lcm1(a, b, c):
    return lcm(lcm(a, b), c)


a, b, c = list(map(int, input().split()))
x = [a, b, c]
x.sort()
a, b, c = x
ar = [0] * 10 ** 5
for i in range(0, 10 ** 5, a):
    ar[i] = 1
for i in range(1, 10 ** 5, b):
    ar[i] = 1
fl = 0
while fl < 10 ** 5 and  ar[fl] == 1:
    fl += 1
for i in range(fl, 10 ** 5, c):
    ar[i] = 1
if 0 in ar:
    print('NO')
else:
    print('YES')