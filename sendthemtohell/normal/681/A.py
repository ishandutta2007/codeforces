from sys import *

n=int(input())
for i in range(n):
    s=input().split()
    rev=[int(s[1]),int(s[2])-int(s[1])]
    if rev[0]>=2400 and rev[1]>0:
        print("YES")
        exit(0)
print("NO")