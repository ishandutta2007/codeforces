T=int(input())
for t in range(T):
	n,m,k=map(int,input().split(' '))
	pp=n//k
	if m<=pp: print(m)
	else:
		m-=pp
		print(pp-(m+k-2)//(k-1))