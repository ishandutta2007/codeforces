n = int(input())
a = []
for i in range(min(n, 82), -1, -1):
	c = n - i
	c += sum([int(j) for j in str(c)])
	if c == n:
		a.append(n - i)
print(len(a))
for i in a:
	print(i)