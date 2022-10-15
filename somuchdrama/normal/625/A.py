n, a, b, c = int(input()), int(input()), int(input()), int(input())
x = (n - c) // (b - c)
if c > n:
	x = 0
y = n - x * (b - c)
x += y // a
print(max(x, n // a))