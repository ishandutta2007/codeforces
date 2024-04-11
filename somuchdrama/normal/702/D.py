from random import randint
d, k, a, b, t = map(int, input().split())
cnt = (d + k - 1) // k
def get(m):
	if k * m >= d:
		return d * a + (cnt - 1) * t
	return k * m * a + max(0, m - 1) * t + (d - k * m) * b
def solvefast():
	if k >= d:
		return d * a
	else:
		l = 0
		r = cnt + 2
		while r - l > 2:
			m1 = (l + r) >> 1
			m2 = m1 + 1
			if get(m2) > get(m1): r = m2
			else: l = m1
		mn = 10 ** 20
		for i in range(max(l - 13, 0), min(l + 13, cnt + 3)):
			mn = min(mn, get(i))
		return mn
print(solvefast())