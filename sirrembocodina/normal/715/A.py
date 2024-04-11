N = int(raw_input())
x = 2
k = 1
while k <= N:
	print(k**3 + 2 * k**2 + k - x // k)
	k += 1
	x = k * (k - 1)