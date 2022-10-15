n, a, b, c, d = map(int, input().split())
ans = 0
for i in range(1, n + 1):
	x = i + b - c
	y = i + a + b - c - d
	z = i + a - d
	ans += n * (1 <= x <= n and 1 <= y <= n and 1 <= z <= n)
print(ans)