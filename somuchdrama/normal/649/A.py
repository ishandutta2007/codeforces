n = int(input())
a = list(map(int, input().split()))
pw = [0] * 40
for i in a:
	x = 1
	pos = 0
	while i % x == 0:
		pw[pos] += 1
		pos += 1
		x *= 2
for i in range(39, -1, -1):
	if pw[i] != 0:
		print(2 ** i, pw[i])
		break