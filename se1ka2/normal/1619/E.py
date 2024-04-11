import heapq

t = int(input())
while t:
	t -= 1
	n = int(input())
	a = list(map(int, input().split()))
	d = [0 for i in range(n + 1)]
	for x in a:
		d[x] += 1
	que = []
	heapq.heapify(que)
	ans = [-1 for i in range(n + 1)]
	s = 0
	for i in range(n + 1):
		ans[i] = s + d[i]
		for j in range(d[i]):
			heapq.heappush(que, -i)
		if not que:
			break
		s += i + heapq.heappop(que)
	print(*ans)