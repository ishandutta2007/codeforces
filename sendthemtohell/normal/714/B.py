from sys import *

n=int(input())
c=[int(z) for z in input().split()]
ee=[]
for i in c:
    if i not in ee:
        ee.append(i)
    if len(ee)>3:
        print("NO")
        exit(0)
ee.sort()
if len(ee)<3 or ee[0]+ee[2]==2*ee[1]:
    print("YES")
else:
    print("NO")