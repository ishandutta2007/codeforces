N=input()
s=raw_input()
s0=s1=0
for i in s:
	if (i=='0'): 
		s0+=1
	else: 
		s1+=1
print N-min(s0,s1)*2