def solveProblem(perm):
	N = len(perm)
	indexOf1 = perm.index(1)
	indexOfN = perm.index(N)
	if indexOf1 > indexOfN:
		# either we move 1 to the end, or N to the first
		# in the first case, we get N - 1 - indexOfN
		# in the second one, we get indexOf1
		return max(N - 1 - indexOfN, indexOf1)
	else:
		# either we move N to the end, or 1 to the first
		# in the first case, we get N - 1 - indexOf1
		# in the second one, we get indexOfN
		return max(N - 1 - indexOf1, indexOfN)

intCount = int(raw_input())
integers = [int(n) for n in raw_input().split()]
print solveProblem(integers)