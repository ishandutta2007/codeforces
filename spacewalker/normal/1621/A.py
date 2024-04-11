t = int(input())
for tc in range(t):
	n, k = map(int, input().split())
	rookPos = [*range(0, n, 2)]
	if len(rookPos) < k:
		print(-1)
	else:
		rookPos = rookPos[:k]
		grid = [['.' for j in range(n)] for i in range(n)]
		for i in rookPos:
			grid[i][i] = 'R'
		for row in grid:
			print(*row, sep="")