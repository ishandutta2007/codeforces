from math import *

n=int(input())
arr=[int(z) for z in input().split()]
arr.sort()
s1=sum(arr[:len(arr)-1])
s2=arr[-1]
assert s2>=s1
print(s2-s1+1)