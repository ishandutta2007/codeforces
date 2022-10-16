from math import *
from sys import *
from queue import *
from decimal import *

n,k=(int(z) for z in input().split())
s=input()
i=0
while i<len(s) and s[i] not in ["G","T"]:
  i+=1
i+=k
while i<len(s) and s[i] not in ["G","T","#"]:
  i+=k
if i>=len(s) or s[i]=="#":
  print("NO")
else:
  print("YES")