for _ in range(int(input())):
	c0=0
	c1=0
	cods=0
	n=int(input())
	for y in range(n):
		s = input()
		zr=s.count('0')
		c0+=zr
		c1+=len(s)-zr
		cods += len(s)%2
	if c0%2+c1%2 <= cods:
		print(n)
	else:
		print(n-1)