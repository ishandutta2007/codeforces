t = int(input())
while t:
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	a.sort()
	ans = a[0]
	for i in range(n - 1):
		ans = max(ans, a[i + 1] - a[i])
	print(ans)