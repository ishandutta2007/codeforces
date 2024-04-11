n,m,k=(int(z) for z in input().split())
M=[]
for i in range(n):
	for j in range(m):
		s=input()
		for p in range(len(s)):
			M+=[int(s[p])]
	if i!=n-1:
		s=input()
res=0
cur=0
for i in range(n):
	for j in range(m):
		for h in range(k):
			if M[cur]==1:
				if 1<=i<=n-2 and M[cur-m*k]+M[cur+m*k]==2:
					res+=1
				elif 1<=h<=k-2 and M[cur-1]+M[cur+1]==2:
					res+=1
				elif 1<=j<=m-2 and M[cur-k]+M[cur+k]==2:
					res+=1
				elif h<=k-2 and j>=1 and M[cur+1]+M[cur-k]==2 and M[cur-k+1]==0:
					res+=1
				elif j<=m-2 and h>=1 and M[cur-1]+M[cur+k]==2 and M[cur+k-1]==0:
					res+=1
				elif h<=k-2 and i>=1 and M[cur+1]+M[cur-m*k]==2 and M[cur-m*k+1]==0:
					res+=1
				elif i<=n-2 and h>=1 and M[cur-1]+M[cur+m*k]==2 and M[cur+m*k-1]==0:
					res+=1 
				elif i<=n-2 and j>=1 and M[cur-k]+M[cur+m*k]==2 and M[cur+m*k-k]==0:
					res+=1
				elif j<=m-2 and i>=1 and M[cur+k]+M[cur-m*k]==2 and M[cur-m*k+k]==0:
					res+=1
			cur+=1
print(res)