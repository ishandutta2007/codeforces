t = int(input())
while t:
	t -= 1
	a = list(map(int, input().split()))
	x = [a[0], a[1], a[6] - a[0] - a[1]]
	print(*x)