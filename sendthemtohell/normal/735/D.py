from math import *
from sys import *
from queue import *
from decimal import *

def pr(i):
  d=2
  while d*d<=i:
    if i%d==0:
      return 0
    d+=1
  return 1

n=int(input())
if n%2==0 and n>2:
  print(2)
elif pr(n):
  print(1)
elif pr(n-2):
  print(2)
else:
  print(3)