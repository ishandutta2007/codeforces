inf=1000000000

N=input()
x=raw_input().split(' ')
for i in range(N): x[i]=int(x[i])
D={}
for i in range(N): D[x[i]]=[0,inf,-inf]
for i in range(N):
	D[x[i]][0]+=1
	D[x[i]][1]=min(D[x[i]][1],i)
	D[x[i]][2]=max(D[x[i]][2],i)
E=D.values()
ans=max(E)[0];ansx=0;ansy=inf;
for i in range(N):
	if ((D[x[i]][0]==ans) and (D[x[i]][2]-D[x[i]][1]<ansy-ansx)):
		ans=D[x[i]][0]
		ansx=D[x[i]][1]
		ansy=D[x[i]][2]
print ansx+1,ansy+1