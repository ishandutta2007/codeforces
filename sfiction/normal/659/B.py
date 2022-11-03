n, r = map(int, raw_input().split())

s = [[] for i in range(0, r)]
for i in range(0, n):
	t = raw_input().split()
	s[int(t[1]) - 1].append([int(t[2]), t[0]])
for x in s:
	x.sort()
	x.reverse()
	print x[0][1] + " " + x[1][1] if len(x) == 2 or x[1][0] != x[2][0] else "?"