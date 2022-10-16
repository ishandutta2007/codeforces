n,k=(int(z) for z in input().split())
if 2*k>=n-1:
	print(n*(n-1)//2)
else:
	print(n*(n-1)//2-(n-2*k)*(n-2*k-1)//2)