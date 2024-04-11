def F(x, y):
	if x >= y:
		return (4 * x + 3 * x * x + 2 * x * x * x - y - 3 * x * y + y * y * y) * y / 6
	else:
		return (4 * y - 3 * y * y + 2 * y * y * y - x + 3 * x * y + x * x * x) * x / 6
T = input()
for i in range(T):
	a, b, c, d = map(int,raw_input().split())
	ans = F(c, d) + F(a - 1, b - 1) - F(a - 1, d) - F(c, b - 1)
	if (ans < 10 ** 10):
		print ans
	else:
		print "...%010d"%(ans % 10 ** 10)