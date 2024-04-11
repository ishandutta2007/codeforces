h1, a1, c = [int(i) for i in input().split()]
h2, a2 = [int(i) for i in input().split()]
y = (h2 + a1 - 1) // a1
x = max((a2 * (y - 1) - h1 + c - a2), 0) // (c - a2)
print(x + y)
for i in range(x):
	print('HEAL')
for i in range(y):
	print('STRIKE')