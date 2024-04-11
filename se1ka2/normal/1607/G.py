import copy

t = int(input())
while t:
	t -= 1
	input()
	n, m = map(int, input().split())
	a = [0 for i in range(n)]
	b = [0 for i in range(n)]
	for i in range(n):
		a[i], b[i] = map(int, input().split())
	aa = [0 for i in range(n)]
	bb = [0 for i in range(n)]
	for i in range(n):
		if a[i] >= m:
			aa[i] = a[i] - m
			bb[i] = b[i]
		else:
			aa[i] = 0
			bb[i] = b[i] - (m - a[i])
	sa = sum(aa)
	sb = sum(bb)
	for i in range(n):
		c = min(a[i] - aa[i], bb[i], bb[i] - (b[i] - m), max(0, sb - sa) // 2)
		aa[i] += c
		bb[i] -= c
		sa += c
		sb -= c
	print(abs(sa - sb))
	for i in range(n):
		print(a[i] - aa[i], b[i] - bb[i])