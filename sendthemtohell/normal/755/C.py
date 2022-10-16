#from math import *
from sys import *
from decimal import *

def gcd(a,b):
    if b:
        return gcd(b,a%b)
    return a

n=int(input())
arr=[int(z) for z in input().split()]
s=set(arr)
res=0
for i in range(n):
    if arr[i]==i+1:
        res+=1
res+=(len(s)-res)//2
print(res)