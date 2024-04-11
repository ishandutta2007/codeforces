dp=[set(),set([(2,13)])]
tbl=dict()
for i in range(1,600):
	dp.append(set())
	for x,y in dp[i]:
		if x not in tbl: tbl[x]=set()
		tbl[x].add(i)
#if y>10**300: continue
		dp[i+1].add((y,12*x))
		dp[i+1].add((y,13*y-12*x))

n=int(input())
if n not in tbl: print "NO"
else:
	print "YES"
	print len(tbl[n])
	print " ".join([str(x) for x in tbl[n]])
	sol = [y for x in tbl[n] for y,z in dp[x] if y!=n]
	sol = list(set(sol))
	sol.sort()
	if len(sol)>1000: sol=sol[:1000]
	print len(sol)
	print " ".join([str(x) for x in sol])