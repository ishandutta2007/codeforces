from sys import *
from decimal import *
from math import *
#from time import clock

n=int(stdin.readline())
#n,m=(int(z) for z in stdin.readline().split())
#arr=[int(z) for z in stdin.readline().split()]
#mat=[]
#for i in range(n):
#    mat.append([int(z) for z in stdin.readline().split()])
u,v=(int(z) for z in stdin.readline().split())
if v==2:
    cmaxr=1899+u
    cminr=-10**12
else:
    cmaxr=10**12
    cminr=1900+u
for i in range(n-1):
    u,v=(int(z) for z in stdin.readline().split())
    if (v==2 and cminr>=1900) or (v==1 and cmaxr<=1899):
        print("Impossible")
        exit(0)
    if v==2:
        cmaxr=min(1899,cmaxr)
    else:
        cminr=max(1900,cminr)
    cmaxr+=u
    cminr+=u
if cmaxr>=10**11:
    print("Infinity")
else:
    print(cmaxr)