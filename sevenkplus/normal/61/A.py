a=str(raw_input())
b=str(raw_input())
n=len(a)
s=""
for i in xrange(n):
	if a[i]==b[i]:
		s+="0"
	else:
		s+="1";
print s