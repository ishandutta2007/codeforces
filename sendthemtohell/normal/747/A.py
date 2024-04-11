from math import *
n=int(input())
a=int(floor(sqrt(n)))
while n%a:
    a-=1
print(a,n//a)