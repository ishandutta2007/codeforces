t=int(input())
while (t):
	t-=1
	n=int(input())
	a=[int(i) for i in input().split()]
	b=[]
	for i in range(1,n):
		#print(i,a[i])
		if (a[i]<a[i-1]):
			b.append([a[i-1]-a[i],i+1])
	#print(b)
	ans=[1]*(n+1)
	b.sort()
	for i in range(n,0,-1):
		if len(b):
			b[-1][0]-=i;
			ans[i]=b[-1][1]
			#print(i,b[-1][1])
			if (b[-1][0]<=0):
				b.pop()
	for i in range(1,n+1):
		print(ans[i],end=' ')
	print()