a = map(int, raw_input().split())[1:]
a.sort()
b = range(10)
for k in xrange(35000):
	for i in xrange(len(b)):
		for j in xrange(len(b)):
			b[i], b[j] = b[j], b[i]
			b[j], b[i] = b[i], b[j]
print " ".join(map(str, a))