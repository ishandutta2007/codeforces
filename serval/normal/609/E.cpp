#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200005
using namespace std;
struct edge
{
	long long x,y,w;
};
edge e[maxn<<1];
struct nedge
{
	long long to,next,w;
};
nedge ne[maxn<<1];
long long cnte,last[maxn];
inline void addedge(long long from,long long to,long long w)
{
	cnte++;
	ne[cnte].to=to;
	ne[cnte].next=last[from];
	ne[cnte].w=w;
	last[from]=cnte;
}
long long n,m,f[maxn],p[maxn],i,j,k,tot;
long long ans,mx;
bool inn[maxn],t[maxn];
bool cmp(long long x,long long y)
{
	return e[x].w<e[y].w;
}
long long get(long long x)
{
	return f[x]?f[x]=get(f[x]):x;
}
long long top[maxn];
long long fa[maxn];
long long depth[maxn];
long long size[maxn];
long long psplay[maxn];
long long hson[maxn];
long long hsone[maxn];
long long tmp[maxn];
long long pos;
inline long long findhedge(long long n,long long pre,long long d)
{
	fa[n]=pre;
	depth[n]=d;
	size[n]=1;
	long long tmp;
	for (tmp=last[n];tmp;tmp=ne[tmp].next)
		if (ne[tmp].to!=pre)
			{
				size[n]+=findhedge(ne[tmp].to,n,d+1);
				if (size[ne[tmp].to]>size[hson[n]])
				{
					hson[n]=ne[tmp].to;
					hsone[n]=tmp;
				}
			}
	return size[n];
}
inline void findpos(long long n,long long sutop,long long w)
{
	top[n]=sutop;
	pos++;
	tmp[pos]=ne[w].w;
	psplay[n]=pos;
	if (hson[n]==0)
		return;
	findpos(hson[n],sutop,hsone[n]);
	long long t;
	for (t=last[n];t;t=ne[t].next)
		if (ne[t].to!=fa[n]&&ne[t].to!=hson[n])
			findpos(ne[t].to,ne[t].to,t);
}
struct stnode
{
	long long l,r,max;
};
stnode segtree[maxn*25];
void init(long long l,long long r,long long p)
{
	segtree[p].l=l;
	segtree[p].r=r;
	if (l==r)
	{
		segtree[p].max=tmp[l];
		return;
	}
	init(l,(l+r)>>1,p<<1);
	init(((l+r)>>1)+1,r,(p<<1)+1);
	segtree[p].max=max(segtree[p].max,max(segtree[p<<1].max,segtree[(p<<1)+1].max));
}
long long getm(long long l,long long r,long long p)
{
	if (segtree[p].l>r||segtree[p].r<l)
		return 0;
	if (segtree[p].l>=l&&segtree[p].r<=r)
		return segtree[p].max;
	if (segtree[p].l==segtree[p].r)
		return segtree[p].max;
	return max(getm(l,r,p<<1),getm(l,r,(p<<1)+1));
}
inline long long getmax(long long x,long long y)
{
	long long ans=0;
	long long u=top[x],v=top[y];
	while (u!=v)
	{
		if (depth[u]<depth[v])
		{
			swap(u,v);
			swap(x,y);
		}
		ans=max(ans,getm(psplay[u],psplay[x],1));
		x=fa[u],u=top[x];
	}
	if (depth[x]>depth[y])
		swap(x,y);
	ans=max(ans,getm(psplay[hson[x]],psplay[y],1));
	return ans;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&e[i].x,&e[i].y,&e[i].w);
		p[i]=i;
	}
	sort(p+1,p+m+1,cmp);
	for (i=1;i<=m;i++)
		if (get(e[p[i]].x)!=get(e[p[i]].y))
		{
			ans+=e[p[i]].w;
			f[get(e[p[i]].x)]=get(e[p[i]].y);
			addedge(e[p[i]].x,e[p[i]].y,e[p[i]].w);
			addedge(e[p[i]].y,e[p[i]].x,e[p[i]].w);
			inn[p[i]]=1;
			tot++;
			if (tot==n-1)
				break;
		}
	findhedge(1,0,1);
	findpos(1,1,0);
	init(1,n,1);
	for (i=1;i<=m;i++)
		if (inn[i])
			printf("%I64d\n",ans);
		else
			printf("%I64d\n",ans+e[i].w-getmax(e[i].x,e[i].y));
	return 0;
}