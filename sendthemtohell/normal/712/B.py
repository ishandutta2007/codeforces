from math import *

def co(s,c):
    t=0
    for i in s:
        if c==i:
            t+=1
    return t

s=input()
if len(s)%2:
    print(-1)
else:
	a=co(s,"D")
	b=co(s,"U")
	c=co(s,"R")
	d=co(s,"L")
	if (a-b)%2:
		print(int(fabs(a-b)//2+fabs(c-d)//2+1))
	else:
		print(int(fabs(a-b)//2+fabs(c-d)//2))