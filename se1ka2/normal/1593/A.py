t = int(input())
while t:
	t -= 1
	a = list(map(int, input().split()))
	l = max(a)
	c = 0
	for i in range(3):
		if a[i] == l:
			c += 1
	if c == 1:
		for i in range(3):
			if a[i] == l:
				print(0, end=' ')
			else:
				print(l + 1 - a[i], end=' ')
	else:
		for i in range(3):
			print(l + 1 - a[i], end=' ')
	print()