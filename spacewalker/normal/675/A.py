def solveProblem(a1, inSeq, d):
	if a1 == inSeq:
		return True
	elif d == 0:
		return a1 == inSeq
	elif d < 0:
		return inSeq < a1 and (b % c) == (a % c)
	else:
		return inSeq > a1 and (b % c) == (a % c)

a, b, c = [int(n) for n in raw_input().split()]
inSequence = solveProblem(a, b, c)
if inSequence:
	print "YES"
else:
	print "NO"