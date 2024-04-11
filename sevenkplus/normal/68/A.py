a,b,c,d,l,r=map(int,raw_input().split())
s=0
for i in xrange(l,r+1):
	if i%a%b%c%d==i:
		s+=1
print s