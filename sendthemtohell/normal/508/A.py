from sys import *
	
MAXN=10**5+228
MOD=10**9+7

def rect(x,y):
    if d.get((x-1,y),0)+d.get((x-1,y-1),0)+d.get((x,y-1),0)==3:
        return 1
    if d.get((x-1,y),0)+d.get((x-1,y+1),0)+d.get((x,y+1),0)==3:
        return 1
    if d.get((x+1,y),0)+d.get((x+1,y-1),0)+d.get((x,y-1),0)==3:
        return 1
    if d.get((x+1,y),0)+d.get((x+1,y+1),0)+d.get((x,y+1),0)==3:
        return 1
    return 0

n,m,k=(int(z) for z in input().split())
d=dict()
for i in range(k):
    u,v=(int(z) for z in input().split())
    if rect(u,v):
        #print("YES")
        print(i+1)
        exit(0)
    d[(u,v)]=1
#print("NO")
print(0)