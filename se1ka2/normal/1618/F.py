x, y = map(lambda x : format(int(x), 'b'), input().split())
f = False
if x == y:
	f = True
z = x
while z[len(z) - 1] == '0':
	z = z[:len(z) - 1]
x = x + '1'
for l in range(60):
	for r in range(60):
		if '1' * l + x + '1' * r == y or '1' * l + x[::-1] + '1' * r == y or '1' * l + z + '1' * r == y or '1' * l + z[::-1] + '1' * r == y:
			f = True
if f:
	print("YES")
else:
	print("NO")