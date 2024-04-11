from sys import *

s=input()
r=input()
if len(s)==len(r):
    g1,g2=0,0
    for i in s:
        if i=="1":
            g1=1
            break
    for i in r:
        if i=="1":
            g2=1
            break
    if not g1^g2:
        print("YES")
        exit(0)
print("NO")