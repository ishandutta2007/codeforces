from sys import *

n=int(input())
a=[int(z) for z in input().split()]

for i in range(n-1):
    if a[i]<0:
        print("NO")
        exit(0)
    a[i]%=2
    if a[i]:
        a[i+1]-=1
if a[n-1]%2:
    print("NO")
else:
    print("YES")