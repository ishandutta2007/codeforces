x, y = [int(s) for s in raw_input().split()]
t = [y, y, y]
ans = 0
while t[0] != x :
	ans += 1
	t[0] = min(x, t[1] + t[2] - 1)
	t.sort()

print ans