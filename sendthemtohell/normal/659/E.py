from sys import *

class graph():
    def __init__(self,n,v):
        self.G=dict()
        for i in range(1,n+1):
            self.G.update([(i,set())])
        self.v=v
        self.length=n
    def AppendEdge(self,a):
        self.G[a[0]].add(a[1])
        if not self.v:
            self.G[a[1]].add(a[0])
    def ShowAdjacent(self,a):
        return self.G[a]
    def ShowLength(self):
        return self.length
    def Show(self):
        print(self.G)

def BFS(G,v):
    Q=[]
    Qp=0
    Q.append((v,-1))
    VisitedVertex[v-1]=1
    ret=1
    while Qp!=len(Q):
        s=Q[Qp]
        Qp+=1
        for i in G.ShowAdjacent(s[0]):
            if not VisitedVertex[i-1]:
                Q.append((i,s[0]))
                VisitedVertex[i-1]=1
            elif i!=s[1]:
                ret=0
    return ret

n,m=(int(z) for z in stdin.readline().split())
G=graph(n,0)
for i in range(m):
    s=[int(z) for z in stdin.readline().split()]
    G.AppendEdge(s)
i=1
res=0
VisitedVertex=[0]*G.ShowLength()
while i<=n:
    if not VisitedVertex[i-1]:
        res+=BFS(G,i)
    i+=1
print(res)