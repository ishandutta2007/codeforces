n,k=input().rstrip().split(' ')
n,k=int(n),int(k)
a=[[0]*n for i in range(n)]
for i in range(n):
	for j in range(n):
		if j==i:
			if k>0:
				a[i][j]=1
				k-=1
		elif j>=i and k>1:
			a[i][j]=a[j][i]=1
			k-=2

if k!=0:
	print(-1)
else:
	for i in range(n):print(' '.join(map(str,a[i])))

#dj