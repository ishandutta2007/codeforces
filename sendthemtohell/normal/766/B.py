from sys import *

n=int(input())
s=[int(z) for z in input().split()]
s.sort()
for i in range(n-2):
    if s[i]+s[i+1]>s[i+2]:
        print("YES")
        exit(0)
print("NO")