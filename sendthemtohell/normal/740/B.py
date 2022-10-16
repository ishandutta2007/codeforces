from math import *
from sys import *
from queue import *
from decimal import *

n,m=(int(z) for z in input().split())
s=[int(z) for z in input().split()]
R=[]
for i in range(m):
  le,r=(int(z) for z in input().split())
  summ=0
  for j in range(le-1,r):
    summ+=s[j]
  R.append(summ)
ans=0
for i in R:
  if i>=0:
    ans+=i
print(ans)