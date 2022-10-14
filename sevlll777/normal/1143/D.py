from math import gcd
n, k = map(int, input().split())
a, b = map(int, input().split())
x, y = n * k, 1
for j in range(1, n + 1):
    for kek in a + b, b - a, a - b, -a-b:
        l = k * j + kek % k
        d = gcd((n * k), l)
        x = min(x, n * k // d)
        y = max(y, n * k // d)
print(x, y)