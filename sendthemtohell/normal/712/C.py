from math import *

def solve(a,b):
	if(a[0]==b):
		return 0
	else:
		return solve([a[1],a[2],min(b,a[1]+a[2]-1)],b)+1

a,b=(int(z) for z in input().split())
if a>b:
	a,b=b,a
print(solve([a,a,a],b))