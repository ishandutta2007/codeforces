from sys import *

n,m,k=(int(z) for z  in input().split())
G=dict()
for i in range(n):
    G[i+1]=set()
e=dict()
for i in range(m):
    u,v,l=(int(z) for z  in input().split())
    G[u].add(v)
    G[v].add(u)
    if e.get((u,v)):
    	e[(u,v)]=min(l,e[(u,v)])
    	e[(v,u)]=min(l,e[(u,v)])
    else:
    	e[(u,v)]=l
    	e[(v,u)]=l
ch=set()
if k!=0:
    c=[int(z) for z in input().split()]
    for i in c:
        ch.add(i)
else:
    print(-1)
    exit(0)

uu=10**10
for i in ch:
    for j in G[i]:
        if j not in ch:
            uu=min(e[(i,j)],uu)
if uu<10**10:
    print(uu)
else:
    print(-1)