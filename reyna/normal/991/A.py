a, b, c, n = map(int, input().split())
rem = n - (a + b - c)
if (rem < 1 or c > a or c > b):
	print(-1)
else:
	print(rem)