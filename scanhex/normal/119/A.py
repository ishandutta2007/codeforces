def gcd(a, b):
    x, y = a, b
    while y != 0:
        x, y = y, x % y
    return x
a, b, n = map(int, input().split())
d = [[None, None] for i in range(n + 1)]
d[0][0] = d[0][1] = 0
for i in range(1, n + 1):
    d[i][0] = 1 ^ d[i - gcd(i, a)][1]
    d[i][1] = 1 ^ d[i - gcd(i, b)][0]
print(1 ^ d[n][0])