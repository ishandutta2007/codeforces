def solve():
	ans = [0 for _ in range(26)]
	n, m = [int(x) for x in input().split()]
	c = [ord(x)-ord('a') for x in input()]
	ile = [0 for _ in range(n)]
	ile[n-1] += 1

	for x in input().split():
		ile[int(x)-1] += 1

	curr = 0
	suf = []

	for x in ile[::-1]:
		curr += x
		suf.append(curr)

	suf = suf[::-1]

	for (i, x) in enumerate(suf):
		ans[c[i]] += x

	print(*ans)

t = int(input())

for _ in range(t):
	solve()