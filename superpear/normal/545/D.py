N=input()
A=raw_input().split(' ')
for i in range(N): A[i]=int(A[i])
A.sort()
ans=0
sm=0
for i in A:
	if (i>=sm): 
		ans=ans+1
		sm=sm+i
print ans