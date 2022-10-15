n, k = map(int, input().split())
p = (n // 2) // (k + 1)
g = p * k
o = n - p - g
print(p, g, o)