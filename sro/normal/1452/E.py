read = lambda: map(int, input().split())
n, m, k = read()
a = []
 
for i in range(m):
	b = list(read())
	b = [sum(b)] + b
	a.append(b)
 
a.sort()
rs = [0] * (m + 1)
 
for i in range(1, n - k + 2):
	l, r, sm = i, i + k - 1, 0
	for j in range(0, m)[::-1]:
		sm += max(0, min(a[j][2], r) - max(a[j][1], l) + 1)
		rs[j] = max(rs[j], sm)
 
ans = rs[0]
 
for i in range(1, n - k + 2):
	l, r, sm = i, i + k - 1, 0
	for j in range(0, m):
		sm += max(0, min(a[j][2], r) - max(a[j][1], l) + 1)
		ans = max(ans, sm + rs[j + 1])
 
print(ans)