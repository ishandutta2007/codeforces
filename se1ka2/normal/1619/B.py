t = int(input())
while t:
	t -= 1
	n = int(input())
	ans = 0
	for i in range(1, n + 1):
		if i ** 6 <= n:
			ans -= 1
		if i ** 3 <= n:
			ans += 1
		if i ** 2 <= n:
			ans += 1
		else:
			break
	print(ans)