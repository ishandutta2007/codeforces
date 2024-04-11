t = int(input())
while t:
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	s = input()
	r = []
	b = []
	for i in range(n):
		if s[i] == 'R':
			r.append(a[i])
		else:
			b.append(a[i])
	r.sort()
	r.reverse()
	b.sort()
	f = True
	for i in range(len(r)):
		if r[i] > n - i:
			f = False
	for i in range(len(b)):
		if b[i] <= i:
			f = False
	if f:
		print("YES")
	else:
		print("NO")