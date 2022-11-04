A = raw_input()
O = "aeiou"
output = ""
c = 0
for x in xrange(len(A)):
	if x > c + 1 and (A[x] not in O) and (A[x - 1] not in O) and (A[x - 2] not in O) and (A[x] != A[x - 1] or A[x - 1] != A[x - 2]):
		output += " "
		c = x
	output += A[x]

print output