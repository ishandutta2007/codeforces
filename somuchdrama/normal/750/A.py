tm = 240
n, k = map(int, input().split())
tm -= k
ans = 0
for i in range(1, n + 1):
	tm -= 5 * i
	if tm < 0:
		break
	ans += 1
print(ans)