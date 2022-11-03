n = 8
top = [['.', 0]] * n
below = [['.', 0]] * n
for i in range(n):
	s = raw_input()
	for j in range(n):
		if s[j] != '.':
			if top[j][0] == '.':
				top[j] = s[j], i
			below[j] = s[j], i

A = 10
B = 10
for i in range(n):
	if top[i][0] == 'W':
		A = min(A, top[i][1])
	if below[i][0] == 'B':
		B = min(B, n - 1 - below[i][1])
print 'A' if A <= B else 'B'