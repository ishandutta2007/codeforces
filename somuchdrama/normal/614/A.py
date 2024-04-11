l, r, k = map(int, input().split())
a = list()
x = 1
while x <= r:
	if l <= x <= r:
		a.append(x)
	x *= k
if len(a) == 0:
	print(-1)
else:
	print(' '.join(map(str, a)))