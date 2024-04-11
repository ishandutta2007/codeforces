from math import *
from sys import *
from queue import *

n=int(input())
s=[int(z) for z in input().split()]
d=dict()
for i in s:
    if not d.get(i):
        d[i]=0
    d[i]+=1
res=0
h=n
while h:
    cur=[]
    for i in range(1001):
        if d.get(i,0):
            d[i]-=1
            cur.append(i)
            h-=1
    assert cur != []
    cur.sort()
    res+=len(cur)-1
print(res)