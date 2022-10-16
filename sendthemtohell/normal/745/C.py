class graph:
    def __init__(self,size):
        self.G=dict()
        for i in range(size):
            self.G[i]=set()
        self.sz=size
        self.ne=0
    def ae(self,u,v):
        self.G[u].add(v)
        self.G[v].add(u)
        self.ne+=1
    def se(self,u):
        return self.G[u]
    def nume(self):
        return self.ne

def dfs(G,v):
    num,mk=1,mark[v]
    vv[v]=1
    for u in G.se(v):
        if not vv[u]:
            n1,mk1=dfs(G,u)
            num+=n1
            mk|=mk1
    return num,mk

n,m,k=(int(z) for z in input().split())
G=graph(n)
hh=[int(z)-1 for z in input().split()]
mark=[0]*n
vv=[0]*n
for i in hh:
    mark[i]=1
for i in range(m):
    u,v=(int(z)-1 for z in input().split())
    G.ae(u,v)
sunmk=0
mkcc=[]
for u in range(n):
    if not vv[u]:
        n2,mk2=dfs(G,u)
        if mk2:
            mkcc.append(n2)
        else:
            sunmk+=n2
mkcc.sort()
ans=0
##print(mkcc,sunmk)
for i in mkcc[:len(mkcc)-1]:
    ans+=i*(i-1)//2
ans+=(mkcc[-1]+sunmk)*(mkcc[-1]+sunmk-1)//2
ans-=m
print(ans)