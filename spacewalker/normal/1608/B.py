from math import ceil

t = int(input())
for tc in range(t):
	n, a, b = map(int, input().split())
	a, b = b, a
	if a + b > n - 2 or abs(a - b) > 1:
		print("-1")
	elif a == b:
		ans = [1]
		for i in range(1, a + 1):
			ans.append(n - i + 1)
			ans.append(i + 1)
		for i in range(a + 2, n - a + 1):
			ans.append(i)
		print(*ans)
	elif a + 1 == b:
		ans = [1]
		for i in range(1, a + 1):
			ans.append(n - i + 1)
			ans.append(i + 1)
		tail = []
		for i in range(a + 2, n - a + 1):
			tail.append(i)
		print(*ans, *tail[::-1])
	elif a == b + 1:
		a, b = b, a
		ans = [1]
		for i in range(1, a + 1):
			ans.append(n - i + 1)
			ans.append(i + 1)
		tail = []
		for i in range(a + 2, n - a + 1):
			tail.append(i)
		aans = ans + tail[::-1]
		print(*[n - v + 1 for v in aans])