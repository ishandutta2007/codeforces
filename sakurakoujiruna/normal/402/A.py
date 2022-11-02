k, a, b, v = [int(x) for x in raw_input().split()]

section = (a + v - 1) / v

for i in range(1, 3000) :
	div = min(b, (k - 1) * i)
	if i + div >= section :
		print i
		break