#from math import *
from sys import *
from decimal import *

def gcd(a,b):
    if b:
        return gcd(b,a%b)
    return a

n,m=(int(z) for z in input().split())
P=set()
B=set()
kek=0
for i in range(n):
    P.add(input())
for j in range(m):
    s=input()
    if s in P:
        P.discard(s)
        kek+=1
    else:
        B.add(s)
kekP=len(P)
kekB=len(B)
canP=kekP+(kek+1)//2
canB=kekB+(kek)//2
if canP>canB:
    print("YES")
else:
    print("NO")