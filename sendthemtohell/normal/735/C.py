from math import *
from sys import *
from queue import *
from decimal import *

n=int(input())
f2=1
f3=2
i=0
while f3<=n:
  i+=1
  f2,f3=f3,f2+f3
print(i)