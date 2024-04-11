t = int(input())
for t in range(t):

	a, s = list(map(int, input().split()))

	gg, ans = 0, ''
	while a > 0:
		x = a % 10
		y = s % 10
		add = y - x
		if add < 0: add += 10
		ans = str(add) + ans
		if add + x < 10:
			a //= 10
			s //= 10
		else:
			a //= 10
			s //= 10
			if s % 10 != (add + x) // 10:
				gg = 1
				break
			else:
				s //= 10

	print(((str(s) if s > 0 else "") + str(ans)).lstrip('0') if not gg else -1)