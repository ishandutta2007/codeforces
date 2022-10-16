from math import *
from sys import *
from queue import *
from decimal import *

n,n1,n2=(int(z) for z in input().split())
s=[int(z) for z in input().split()]
s.sort()
for i in range(n//2):
  s[i],s[n-1-i]=s[n-1-i],s[i]
sum1=0
sum2=0
if n1>n2:
  n1,n2=n2,n1
for i in range(n1):
  sum1+=s[i]
for i in range(n1,n1+n2):
  sum2+=s[i]
print(Decimal(sum1)/Decimal(n1)+Decimal(sum2)/Decimal(n2))