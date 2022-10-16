from math import *
from sys import *

M=[0]*367
F=[0]*367
n=int(stdin.readline())
for i in range(n):
    nn=[z for z in stdin.readline().split()]
    if nn[0]=="M":
        for j in range(int(nn[1]),int(nn[2])+1):
            M[j]+=1
    else:
        for j in range(int(nn[1]),int(nn[2])+1):
            F[j]+=1
mx=0
for i in range(367):
    mx=max(mx,min(M[i],F[i]))
print(2*mx)