n, m = map(int, input().split())
a = list(map(int, input().split()))
ans = [0] * (n + 1)
for i in range(m - 1):
	pot = (a[i + 1] - a[i] + n) % n
	if pot == 0: pot = n
	if ans[a[i]] == 0 or ans[a[i]] == pot: ans[a[i]] = pot
	else:
		print(-1)
		exit(0)
used = [False] * (n + 1)
for i in ans:
	used[i] = True
for i in range(1, n + 1):
	if ans[i] == 0:
		for j in range(1, n + 1):
			if not used[j]:
				used[j] = True
				ans[i] = j
				break
print(' '.join(map(str, ans[1:])) if all(used[1:]) else -1)