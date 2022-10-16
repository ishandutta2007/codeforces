from sys import *

k=int(input())
s=input()
ee=set()
for i in s:
    ee.add(i)
if k>len(ee):
    print("NO")
    exit(0)
print("YES")
i=1
cur=s[0]
num=k-1
ee.discard(s[0])
while i<len(s):
    if s[i] in ee and num:
        print(cur)
        ee.discard(s[i])
        num-=1
        cur=s[i]
    else:
        cur+=s[i]
    i+=1
print(cur)