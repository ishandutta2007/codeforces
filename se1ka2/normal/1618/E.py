t = int(input())
while t:
	t -= 1
	n = int(input())
	b = list(map(int, input().split()))
	s = sum(b) // (n * (n + 1) // 2)
	if s * n * (n + 1) // 2 != sum(b):
		print("NO")
		continue
	ans = [0 for i in range(n)]
	f = True
	for i in range(n):
		if (s - (b[i] - b[i - 1])) % n:
			f = False
			break
		ans[i] = (s - (b[i] - b[i - 1])) // n
	if f and all([ans[i] > 0 for i in range(n)]):
		print("YES")
		print(*ans)
	else:
		print("NO")