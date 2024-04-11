for _ in range(int(input())):
	n,m=map(int,input().split())
	a=list(map(int,input().split()))
	if n==2 or m < n:
		print(-1)
	else:
		s=sum(a)
		for i in range(n):
			a[i]=[a[i],i+1]
		a.sort()
		print(2*s+(m-n)*(a[0][0]+a[1][0]))
		for i in range(1,n+1):
			print(i,1+i%n)
		for i in range(m-n):
			print(a[0][1],a[1][1])