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

n=int(input())
s=input()
f=[int(z) for z in input().split()]
##G=graph(n+2,1)
Vis=[0]*n
k=1
i=0
Vis[0]=1
while k!=0:
	if s[i]=='>':
		t=i+f[i]
		if t>=n:
			print('FINITE')
			k=0
		elif Vis[t]:
			print('INFINITE')
			k=0
		else:
			Vis[t]=1
			i=t
	else:
		t=i-f[i]
		if t<0:
			print('FINITE')
			k=0
		elif Vis[t]:
			print('INFINITE')
			k=0
		else:
			Vis[t]=1
			i=t