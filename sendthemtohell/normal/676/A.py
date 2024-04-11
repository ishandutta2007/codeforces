n=int(input())
s=[int(z) for z in input().split()]
d=0
for i in range(n):
	if s[i]==1 or s[i]==n:
		d=max(d,i,n-1-i)
print(d)