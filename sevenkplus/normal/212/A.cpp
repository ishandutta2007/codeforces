#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 210
#define M 5010
int n,m,k,s,px[M],py[M],dx[N],dy[N],c[M];
int he[N*2],ad[M*4],ne[M*4],di[M*4],wi[M*4],t;
void addE(int x,int y,int z,int w)
{
	++t,ne[t]=he[x],he[x]=t,ad[t]=y,di[t]=z,wi[t]=w;
	++t,ne[t]=he[y],he[y]=t,ad[t]=x,di[t]=0,wi[t]=-w;
}
#define INF 1000000007
int q[N*N*4],pr[N*2],ed[N*2],d[N*2];bool v[N*2];
bool spfa(int s,int t,int c)
{
	memset(v,0,sizeof v);
	for(int i=0;i<c;i++)d[i]=INF;
	int l=0,r=1;q[0]=s,v[s]=1,d[s]=0;
	while(l<r)
	{
		int x=q[l++];v[x]=0;
		for(int p=he[x];p;p=ne[p])if(di[p])
			if(d[x]+wi[p]<d[ad[p]])
			{
				d[ad[p]]=d[x]+wi[p],pr[ad[p]]=x,ed[ad[p]]=p;
				if(!v[ad[p]])v[ad[p]]=1,q[r++]=ad[p];
			}
	}
	return d[t]<INF;
}
int ff(int s,int t,int c)
{
	int S=0,T=0;
	while(spfa(s,t,c))
	{
		int nf=INF;
		for(int i=t;i!=s;i=pr[i])nf=min(nf,di[ed[i]]);
		S+=nf*d[t],T+=nf;
		for(int i=t;i!=s;i=pr[i])di[ed[i]]-=nf,di[ed[i]^1]+=nf;
	}
	return S;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=0;i<k;i++)
		scanf("%d%d",px+i,py+i),dx[--px[i]]++,dy[--py[i]]++;
	int S=0;
	for(int i=0;i<n;i++)S+=!!(dx[i]%s);
	for(int i=0;i<m;i++)S+=!!(dy[i]%s);
	printf("%d\n",S);
	for(int i=s;i;i--)
	{
		memset(he,0,sizeof he),t=1;
		int le=n+m,ri=le+1;
		for(int j=0;j<k;j++)
			if(!c[j])addE(px[j],n+py[j],1,0);
		for(int j=0;j<n;j++)
		{
			addE(le,j,dx[j]/i,0);
			if(dx[j]%i)addE(le,j,1,1);
		}
		for(int j=0;j<m;j++)
		{
			addE(n+j,ri,dy[j]/i,0);
			if(dy[j]%i)addE(n+j,ri,1,1);
		}
		ff(le,ri,ri+1);
		for(int j=0,z=0;j<k;j++)
			if(!c[j]){z+=2;if(!di[z])c[j]=i,dx[px[j]]--,dy[py[j]]--;}
	}
	for(int i=0;i<k;i++)
		printf("%d%c",c[i],i==k-1?'\n':' ');
	return 0;
}