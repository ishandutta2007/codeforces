#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,i;
const int maxv=300005;
const int maxn=600005;
int h[maxv],cnt;
int to[maxn],nx[maxn];
long long wt[maxn];
int u,y;
long long w;
bool chk[maxv];
long long lg[maxv];
int p[maxv],pd;
long long v[maxv],ans;
long long ret,qr,out;
bool sp;
void addedge(int u,int v,long long w)
{
	cnt++;
	to[cnt]=v;
	wt[cnt]=w;
	nx[cnt]=h[u];
	h[u]=cnt;
}
void dfs(int u,int from,int d)
{
	if (u==n)
	{
		chk[u]=1;
		p[d]=n;
		pd=d;
	}
	int cq=0;
	for (int i=h[u];i;i=nx[i])
		if (to[i]!=from)
		{
			dfs(to[i],u,d+1);
			if (!chk[to[i]])
			{
				if (lg[to[i]]+wt[i]>lg[u])
					lg[u]=lg[to[i]]+wt[i];
				cq++;
			}
			if (chk[to[i]])
			{
				chk[u]=1;
				p[d]=u;
				v[d]=wt[i];
			}
		}
	if (cq>=2)
		sp=1;
}
long long mx[maxn*2],pl[maxn*2];
void add(int u,int l,int r,int ql,int qr,long long v)
{
	if (qr<l||r<ql)
		return;
	if (ql<=l&&r<=qr)
	{
		pl[u]+=v;
		mx[u]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if (pl[u]!=0)
	{
		mx[u<<1]+=pl[u];
		mx[u<<1^1]+=pl[u];
		pl[u<<1]+=pl[u];
		pl[u<<1^1]+=pl[u];
		pl[u]=0;
	}
	add(u<<1,l,mid,ql,qr,v);
	add(u<<1^1,mid+1,r,ql,qr,v);
	mx[u]=max(mx[u<<1],mx[u<<1^1]);
}
long long qry(int u,int l,int r,int ql,int qr)
{
	if (qr<l||r<ql)
		return -0x3ffffffffffff;
	if (ql<=l&&r<=qr)
		return mx[u];
	int mid=(l+r)>>1;
	if (pl[u]!=0)
	{
		mx[u<<1]+=pl[u];
		mx[u<<1^1]+=pl[u];
		pl[u<<1]+=pl[u];
		pl[u<<1^1]+=pl[u];
		pl[u]=0;
	}
	long long ret=-0x3ffffffffffff;
	ret=max(ret,qry(u<<1,l,mid,ql,qr));
	ret=max(ret,qry(u<<1^1,mid+1,r,ql,qr));
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++)
	{
		scanf("%d%d%lld",&u,&y,&w);
		addedge(u,y,w);
		addedge(y,u,w);
	}
	dfs(1,0,1);
	ret=-0x3ffffffffffff;
	for (i=1;i<=pd;i++)
	{
		if (i!=1&&qry(1,1,pd,1,i-1)+lg[p[i]]>ret)
			ret=qry(1,1,pd,1,i-1)+lg[p[i]];
		add(1,1,pd,i,i,(lg[p[i]]==0?-0x3fffffffffffff:lg[p[i]]));
		add(1,1,pd,1,i,-v[i]);
		ans+=v[i];
	}
	memset(pl,0,sizeof(pl));
	memset(mx,0,sizeof(mx));
	for (i=pd;i;i--)
	{
		if (i!=pd&&qry(1,1,pd,i+1,pd)+lg[p[i]]>ret)
			ret=qry(1,1,pd,i+1,pd)+lg[p[i]];
		add(1,1,pd,i,i,(lg[p[i]]==0?-0x3fffffffffffff:lg[p[i]]));
		add(1,1,pd,i,pd,-v[i-1]);
	}
	for (i=2;i<pd;i++)
		if (-v[i-1]-v[i]>ret)
			ret=-v[i-1]-v[i];
	for (i=1;i<=m;i++)
	{
		scanf("%lld",&qr);
		if (ret+qr<0&&!sp)
			out=ans+ret+qr;
		else
			out=ans;
		printf("%lld\n",out);
	}
	return 0;
}