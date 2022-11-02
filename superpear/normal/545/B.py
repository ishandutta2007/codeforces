S1=raw_input()
S2=raw_input()
s=0
for (i,j) in zip(S1,S2):
	if (i!=j): s=s+1
if (s%2==1):
	print 'impossible'
else:
	s=0
	ans=[]
	for (i,j) in zip(S1,S2):
		if (i!=j):
			s=s+1
			if (s%2==0):
				ans.append(i)
			else:
				ans.append(j)
		else:
			ans.append(i)
	print ''.join(ans)