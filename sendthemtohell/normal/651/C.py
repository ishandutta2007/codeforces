n=int(input())
d1=dict()
d2=dict()
d3=dict()
res=0
for i in range(n):
    x,y=(int(z) for z in input().split())
    res+=d1.get(x,0)
    res+=d2.get(y,0)
    res-=d3.get((x,y),0)
    if not d1.get(x):
        d1[x]=0
    if not d2.get(y):
        d2[y]=0
    if not d3.get((x,y)):
        d3[(x,y)]=0
    d1[x]+=1
    d2[y]+=1
    d3[(x,y)]+=1
    ##print(d1,d2,d3)
print(res)