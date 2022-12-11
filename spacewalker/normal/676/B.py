def solveProblem(n, t):
	glasses = [[0 for j in xrange(i + 1)] for i in xrange(n)]
	glasses[0][0] = t #we pour t glasses' worth of champagne
	for i in xrange(n): #for each row in the glass tower
		for j in xrange(i+1): #for each glass in that row
			if glasses[i][j] > 1: #if we overflowed this glass
				overflow = glasses[i][j] - 1
				glasses[i][j] = 1
				if i != n-1: #if we're not on the last row, overflow it to the next glasses
					glasses[i+1][j] += overflow / 2.0
					glasses[i+1][j+1] += overflow / 2.0
	count = 0
	for i in xrange(n):
		for j in xrange(i+1):
			if glasses[i][j] == 1:
				count += 1
	return count

n, t = [int(n) for n in raw_input().split()]
print solveProblem(n, t)