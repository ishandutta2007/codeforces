n, h = map(int, input().split())
s = ''
for i in range(1, n):
	s += "%.6f " % (i * h * h / n) ** 0.5
print(s)