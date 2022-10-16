from math import *
n,a=(int(z) for z in input().split())
x=[int(z) for z in input().split()]
x.sort()
if n==1:
    print(0)
else:
    print(int(min(fabs(a-x[1])+fabs(x[-1]-x[1]),fabs(a-x[-1])+fabs(x[-1]-x[1]),fabs(a-x[-2])+fabs(x[-2]-x[0]),fabs(a-x[0])+fabs(x[-2]-x[0]) )))