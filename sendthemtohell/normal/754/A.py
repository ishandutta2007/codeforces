from math import *
from sys import *
from decimal import *

def gcd(a,b):
    if b:
        return gcd(b,a%b)
    return a

n=int(input())
arr=[int(z) for z in input().split()]
fst=[0]
for i in range(n):
    if arr[i]:
        fst.append(i+1)
fst.pop()
fst.append(n)
if len(fst)>=2:
    print("YES")
    print(len(fst)-1)
    for i in range(len(fst)-1):
        print(fst[i]+1,fst[i+1])
else:
    print("NO")