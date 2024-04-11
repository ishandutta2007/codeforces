x = input()
a = 0

for i in range(len(x)):
	a *= 2
	if x[-i] == '1':
		a += 1

ans = 0
x = 1
while x < a:
	ans += 1
	x *= 4

print(ans)