from sys import *

n=int(input())
if n>26:
    print(-1)
    exit(0)
s=input()
ee=set()
for i in s:
    ee.add(i)
print(n-len(ee))