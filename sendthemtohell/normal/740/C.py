from math import *
from sys import *
from queue import *
from decimal import *

n,m=(int(z) for z in input().split())
e=n
for i in range(m):
  j,k=(int(z) for z in input().split())
  e=min(e,k-j+1)
res=[]
for i in range(n):
  res.append(i%e)
print(e)
print(' '.join(map(str,res)))