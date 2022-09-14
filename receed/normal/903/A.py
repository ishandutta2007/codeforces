n = int(input())
for i in range(n):
	t = int(input())
	for j in range(7):
		if j * 3 <= t and (t - j * 3) % 7 == 0:
			print('YES')
			break
	else:
		print('NO')