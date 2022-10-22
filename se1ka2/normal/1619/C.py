from functools import reduce

t = int(input())
while t:
	t -= 1
	a, s = map(int, input().split())
	b = []
	f = True
	while s:
		if a > s:
			f = False
			break
		if a % 10 <= s % 10:
			b.append(s % 10 - a % 10)
			a //= 10
			s //= 10
		elif s // 10 % 10 == 1:
			b.append(s % 10 + 10 - a % 10)
			a //= 10
			s //= 100
		else:
			f = False
			break
	if f:
		b.reverse()
		b = reduce(lambda x, y : x * 10 + y, b)
		print(b)
	else:
		print(-1)