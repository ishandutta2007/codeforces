n = int(input())
h = 0
south = 20000
for i in range(n):
	t, d = input().split()
	t = int(t)
	if d[0] in 'WE': 
		if h == 0 or h == south:
			h = 228
			break
		else:
			continue
	if d[0] == 'N':
		if h == 0:
			h = 228
			break
		else:
			h -= t
	if d[0] == 'S':
		if h == south:
			h = 228
			break
		else:
			h += t
	if h < 0 or h > south:
		h = 228
		break
print(("YES", "NO")[h != 0])