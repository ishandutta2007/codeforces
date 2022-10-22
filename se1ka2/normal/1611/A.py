t = int(input())
while t:
	t -= 1
	n = list(map(int, input()))
	if n[len(n) - 1] % 2 == 0:
		print(0)
	elif n[0] % 2 == 0:
		print(1)
	else:
		f = False
		for d in n:
			if d % 2 == 0:
				print(2)
				f = True
				break;
		if not f:
			print(-1)