eps = 1e-9
t = int(input())
for t in range(t):
	n = int(input())
	a = list(map(int, input().split(' ')))

	a = sorted(a)

	cnt = [0] * (n+1)
	for x in a: cnt[x] += 1

	stk = []
	j, tot = 0, 0

	for i in range(n + 1):

		while j < n and a[j] <= i - 1:
			stk.append(a[j]); j += 1

		if len(stk) == 0 and i > 0:
			for j in range(i, n + 1):
				print("-1", end=' ')
			break

		if len(stk) > 0:
			tot += i - 1 - stk[-1]
			stk.pop()

		print(tot + cnt[i], end = ' ')
	
	print()