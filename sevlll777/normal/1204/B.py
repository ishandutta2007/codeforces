n, l, r = map(int, input().split())
x = 2 ** l - 1 + n - l
y = 2 ** (r - 1) - 1 + 2 ** (r - 1) * (n - r + 1)
print(x, y)