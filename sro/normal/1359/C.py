T=int(input())
for t in range(T):
	h,c,t=map(int,input().split())
	h*=2;c*=2;t*=2
	m=(h+c)//2
	if t<=m:
		print(2)
	else:
		hc,tc=h-m,t-m
		tms=hc//tc
		apr=[2434841,1]
		for i in range(tms-5,tms+5):
			if i%2 and abs(tc-hc/i)<apr[0]:
				apr=[abs(tc-hc/i),i]
		print(apr[1])