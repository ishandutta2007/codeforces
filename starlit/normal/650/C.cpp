#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int n,m,to[N<<1],hd[N<<1],lk[N],cnt,deg[N],dis[N];
inline void add(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
int i,j,k,f[N],v[N],q[N],h,t;
struct pt{int val,ind;}a[N];
bool cmp(pt x,pt y){return x.val<y.val;}
int getr(int x)
{return f[x]^x?f[x]=getr(f[x]):x;}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",&v[i*m+j]),f[i*m+j]=i*m+j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		a[j]={v[i*m+j],i*m+j};
		sort(a,a+m,cmp);
		for(j=1;j<m;j++)
		{
			if(a[j].val>a[j-1].val)add(a[j-1].ind,a[j].ind);
			else f[getr(a[j-1].ind)]=getr(a[j].ind);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		a[j]={v[j*m+i],j*m+i};
		sort(a,a+n,cmp);
		for(j=1;j<n;j++)
		{
			if(a[j].val>a[j-1].val)add(a[j-1].ind,a[j].ind);
			else f[getr(a[j-1].ind)]=getr(a[j].ind);
		}
	}
	for(i=0;i<n*m;i++)
	if(getr(i)!=i)
	{
		for(j=lk[i],k=hd[j];j;j=k,k=hd[j])
		hd[j]=lk[getr(i)],lk[f[i]]=j;
	}
	for(i=0;i<n*m;i++)
	if(getr(i)==i)
	{
		for(j=lk[i];j;j=hd[j])
		deg[to[j]=getr(to[j])]++;
	}
	for(i=0;i<n*m;i++)
	if(f[i]==i&&!deg[i])
	q[t++]=i;
	while(h<t)
	{
        if(!dis[k=q[h++]])
		dis[k]=1;
		for(i=lk[k];i;i=hd[i])
		{
			dis[to[i]]=max(dis[to[i]],dis[k]+1);
			deg[to[i]]--;
			if(!deg[to[i]])q[t++]=to[i];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		printf("%d ",dis[f[i*m+j]]);
		puts("");
	}
}