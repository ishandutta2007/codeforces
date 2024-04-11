n, k = [int(x) for x in raw_input().split()]

for i in range(0, n + 1) :
	e = n - i
	m = k - 2 * i
	if 3 * e <= m and m <= 5 * e :
		print i
		break