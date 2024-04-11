t = int(input())
while t:
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	if a[0] == n or a[n - 1] == n:
		for x in a[::-1]:
			print(x, end=' ')
		print()
	else:
		print(-1)