from sys import *

m,n=(int(z) for z in input().split())
s=[]
d={"C","M","Y"}
for i in range(m):
    s.append(input())
for i in range(m):
    for j in s[i]:
        if j in d:
            print("#Color")
            exit(0)
print("#Black&White")