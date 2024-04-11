a = sorted([int(i) for i in input().split()])
if a[0] * a[1] + a[1] * a[2] + a[2] * a[0] < a[0] * a[1] * a[2] or a[0] == 2 and a[1] == 3:
	print('NO')
else:
	print('YES')