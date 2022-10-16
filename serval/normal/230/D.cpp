#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100005;
const int maxe=200005;
const int maxp=3200005;
const int maxv=1000000000;
int n,m;
int i,a,b,c;
int h[maxn],to[maxe],nx[maxe],wt[maxe],et;
int rt[maxn],nt;
bool full[maxp];
int mval[maxp],lch[maxp],rch[maxp];
int q[maxn],ql,qr,qt;
int dist[maxn];
bool inq[maxn];
void addedge(int u,int v,int w)
{
	et++;
	to[et]=v;
	wt[et]=w;
	nx[et]=h[u];
	h[u]=et;
}
void update(int u,int l,int r,int mid)
{
	if (lch[u]==0)
	{
		mval[u]=l;
		return;
	}
	if (rch[u]==0)
	{
		mval[u]=min(mval[lch[u]],mid+1);
		return;
	}
	mval[u]=min(mval[lch[u]],mval[rch[u]]);
	full[u]=full[lch[u]]&&full[rch[u]];
}
void ins(int &u,int l,int r,int p)
{
	if (p<l||p>r)
		return;
	if (u==0)
		u=++nt;
	if (l==r)
	{
		full[u]=1;
		mval[u]=maxv;
		return;
	}
	int mid=((long long)l+(long long)r)>>1;
	ins(lch[u],l,mid,p);
	ins(rch[u],mid+1,r,p);
	update(u,l,r,mid);
}
int qry(int u,int l,int r,int p)
{
	if (p<l&&u>0)
		return mval[u];
	if (p<l)
		return l;
	if (p>r)
		return maxv;
	if (u==0&&p+1<=r)
		return p+1;
	if (u==0)
		return maxv;
	if (l==r)
		return maxv;
	int mid=((long long)l+(long long)r)>>1;
	return min(qry(lch[u],l,mid,p),qry(rch[u],mid+1,r,p));
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
		addedge(b,a,c);
	}
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a);
		while (a--)
		{
			scanf("%d",&b);
			ins(rt[i],0,maxv,b);
		}
		dist[i]=maxv*2;
	}
	ql=qr=1;
	qt=1;
	q[1]=1;
	inq[1]=1;
	dist[1]=0;
	while (qt)
	{
		c=qry(rt[q[ql]],0,maxv,dist[q[ql]]-1);
		if (c<dist[q[ql]])
			c=dist[q[ql]];
		for (i=h[q[ql]];i;i=nx[i])
			if (c+wt[i]<dist[to[i]])
			{
				dist[to[i]]=c+wt[i];
				if (!inq[to[i]])
				{
					qt++;
					qr++;
					if (qr==maxn)
						qr=1;
					inq[to[i]]=1;
					q[qr]=to[i];
				}
			}
		inq[q[ql]]=0;
		ql++;
		if (ql==maxn)
			ql=1;
		qt--;
	}
	if (dist[n]!=2*maxv)
		printf("%d\n",dist[n]);
	else
		printf("%d\n",-1);
	return 0;
}