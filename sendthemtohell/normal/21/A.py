from sys import *

def g(c):
    if "a"<=c<="z" or "A"<=c<="Z" or c in [str(z) for z in range(10)] or c=="_":
        return 1
    return 0

def good(s):
    if 1<=len(s)<=16:
        for i in s:
            if not g(i):
                return 0
        return 1
    return 0

s=input()
s=s.split("@")
if len(s)!=2:
    print("NO")
    exit (0)
ns=[s[0]]+s[1].split("/")
if len(ns)>3 or len(ns[1])>32:
    print("NO")
    exit(0)

nss=[ns[0]]+ns[1].split(".")+ns[2:]
for i in nss:
    if not good(i):
        print("NO")
        exit(0)
print("YES")