n = int(raw_input())
c = raw_input().split()
q = [c]
v = set([tuple(c)])
while len(q) > 0:
	c = q.pop()
	if len(c) == 1:
		print 'YES'
		exit()
	for i in [-2,-4]:
		if len(c)>=abs(i) and (c[-1][0]==c[i][0] or c[-1][1]==c[i][1]):
			d = list(c)
			d[i] = d[-1]
			d.pop()
			if tuple(d) not in v:
				v.add(tuple(d))
				q.append(d)
print 'NO'