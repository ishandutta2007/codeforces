n = int(input())
d = (-7 + 8 * n)
x = int((d ** 0.5 - 1) / 2)
print(n - x * (x + 1) // 2)