n,m,q=(int(z) for z in input().split())
s=[]
res=[]
for i in range(n):
	res.append([0]*m)
for i in range(q):
	s.append([int(z) for z in input().split()])
while len(s)>0:
	if s[-1][0]==3:
		res[s[-1][1]-1][s[-1][2]-1]=s[-1][3]
	elif s[-1][0]==2:
		r=res[-1][s[-1][1]-1]
		for i in range(n-1,0,-1):
			res[i][s[-1][1]-1]=res[i-1][s[-1][1]-1]
		res[0][s[-1][1]-1]=r
	else:
		r=res[s[-1][1]-1][-1]
		for i in range(m-1,0,-1):
			res[s[-1][1]-1][i]=res[s[-1][1]-1][i-1]
		res[s[-1][1]-1][0]=r
	s.pop()
for i in range(n):
	print(' '.join(map(str,res[i])))