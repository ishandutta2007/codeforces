N=input();
x=raw_input().split(' ');
flag=1;
for i in range(N):
	if (x[i]=='1'):
		flag=0
if (flag==0):
	print -1
else:
	print 1