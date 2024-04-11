from sys import *

n=int(stdin.readline())
pr=[int(z) for z in stdin.readline().split()]
pr.sort()
q=int(stdin.readline())
for i in range(q):
    m=int(stdin.readline())
    l,r=0,n+1
    while r-l>1:
        mid=(l+r)>>1
        if pr[mid-1]>m:
            r=mid
        else:
            l=mid
    print(l)