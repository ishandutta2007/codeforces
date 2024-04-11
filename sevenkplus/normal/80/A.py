def prime(n):
	for i in range(2,n-1):
		if n%i==0:
			return 0
	return 1
n,m=map(int,raw_input().split())
n+=1
while not prime(n):
	n+=1
if m==n:
	print "YES"
else:
	print "NO"