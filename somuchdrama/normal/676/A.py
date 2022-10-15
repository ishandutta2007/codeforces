n = int(input())
a = input().split()
b = 0
c = 0
for i in range(n):
	if a[i] == '1':
		b = i
	if a[i] == str(n):
		c = i
if c < b: b, c = c, b
print(max(c, n - b - 1))