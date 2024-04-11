n,m=(int(z) for z in input().split())
s=[int(z) for z in input().split()]
t=set(s)
q=0
i=1
res=[]
while q+i<=m and i<1000000000:
	if i not in t:
		q+=i
		res.append(str(i))
	i+=1
print(len(res))
print(' '.join(res))