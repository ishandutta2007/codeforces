import collections

t = int(input())
while t:
	t -= 1
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	a.sort()
	c = collections.Counter(a[n - k * 2:])
	ans = sum(a[:n - k * 2])
	if c:
		ans += max(0, c.most_common()[0][1] - k)
	print(ans)