from sys import *

n=int(input())
hi=20000
for i in range(n):
    s=input().split()
    if s[1][0]=="S":
        hi-=int(s[0])
    elif s[1][0]=="N":
        hi+=int(s[0])
    else:
        if hi in [0,20000]:
            print("NO")
            exit(0)
    if not 0<=hi<=20000:
        print("NO")
        exit(0)
if hi==20000:
    print("YES")
else:
    print("NO")