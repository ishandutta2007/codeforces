/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int n,m,b[N],w,vi[N],cnt;
vector <pair<int,int> > p[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct node
{
	int v,id;
}dp[N];
bool operator <(node a,node b){return a.v<b.v;}
bool operator !=(node a,node b){return a.v!=b.v||a.id!=b.id;}
inline void ckmax(node &a,node b){a=((a<b)?b:a);}
namespace seg
{
	#define ls x+x
	#define rs x+x+1
	node tag[N*4],MAX[N*4];
	inline void pushup(int x){MAX[x]=max(MAX[ls],MAX[rs]);}
	inline void pushdown(int x)
	{
		if (tag[x]!=(node){0,n+1})
		{
			ckmax(MAX[ls],tag[x]);ckmax(MAX[rs],tag[x]);
			ckmax(tag[ls],tag[x]);ckmax(tag[rs],tag[x]);
			tag[x]=(node){0,n+1};
		}
	}
	void build(int x,int l,int r)
	{
		MAX[x]=tag[x]=(node){0,n+1};
		if (l==r) return;
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
	}
	void change(int x,int l,int r,int ll,int rr,node v)
	{
		if (ll<=l&&rr>=r){ckmax(MAX[x],v);ckmax(tag[x],v);return;}
		int mid=(l+r)>>1;pushdown(x);
		if (ll<=mid) change(ls,l,mid,ll,rr,v);
		if (rr>mid) change(rs,mid+1,r,ll,rr,v);
		pushup(x);
	}
	node query(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r) return MAX[x];
		int mid=(l+r)>>1;node ans=(node){0,n+1};pushdown(x);
		if (ll<=mid) ckmax(ans,query(ls,l,mid,ll,rr));
		if (rr>mid) ckmax(ans,query(rs,mid+1,r,ll,rr));
		return ans;
	}
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int pos=read(),l=read(),r=read();
		b[++w]=l;b[++w]=r;
		p[pos].push_back(m_k(l,r));
	}
	sort(b+1,b+1+w);
	w=unique(b+1,b+1+w)-b-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<len(p[i]);j++)
		{
			p[i][j].first=lower_bound(b+1,b+1+w,p[i][j].first)-b;
			p[i][j].second=lower_bound(b+1,b+1+w,p[i][j].second)-b;
		}
	}
	seg::build(1,1,w);
	for (int i=n;i>=1;i--)
	{
		for (auto j:p[i])
		{
			node tmp=seg::query(1,1,w,j.first,j.second);
			tmp.v++;
			ckmax(dp[i],tmp);
		}
		node now=dp[i];now.id=i;
		for (auto j:p[i]) seg::change(1,1,w,j.first,j.second,now);
	}
	node ans=(node){0,0};
	int wh;
	for (int i=1;i<=n;i++) if (ans<dp[i]) ckmax(ans,dp[i]),wh=i;
	int x=ans.id;vi[wh]=1;
	while (x!=n+1)
	{
		vi[x]=1;
		x=dp[x].id;
	}
	printf("%d\n",n-ans.v);
	for (int i=1;i<=n;i++) if (!vi[i]) printf("%d ",i);
	printf("\n");
}