def nth(c):
	return ord(c) - ord('a')

t = int(input())
while t:
	t -= 1
	x, n = map(int, input().split())
	if abs(x) % 2:
		if n % 4 == 0:
			print(x)
		if n % 4 == 1:
			print(x + n)
		if n % 4 == 2:
			print(x - 1)
		if n % 4 == 3:
			print(x - 1 - n)
	else:
		if n % 4 == 0:
			print(x)
		if n % 4 == 1:
			print(x - n)
		if n % 4 == 2:
			print(x + 1)
		if n % 4 == 3:
			print(x + 1 + n)