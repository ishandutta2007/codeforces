n = int(input())
a = int(input())
b = int(input())
c = int(input())

print(min (a, b) * min (1, n - 1) + min ([a, b, c]) * max (0, n - 2))