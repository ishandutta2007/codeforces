t = int(input())
while t:
	t -= 1
	a, b = map(int, input().split())
	if a < b:
		a, b = b, a
	if b * 3 < a:
		print(b)
	else:
		print((a + b) // 4)