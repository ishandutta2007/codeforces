/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=4*1e5+100;
int n,m,dg[N],d[N],vi[N],rt[N];
vector <pair<int,int> > e[N];
vector <int> p[N],E[N];
set <pair<int,int> > s;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
namespace seg
{
	struct node
	{
		int ls,rs,sum,MIN;
	}sh[N*20];
	int cnt;
	void init(){sh[0].MIN=inf;}
	void pushup(int x)
	{
		sh[x].sum=sh[sh[x].ls].sum+sh[sh[x].rs].sum;
		sh[x].MIN=min(sh[sh[x].ls].MIN+sh[sh[x].rs].sum,sh[sh[x].rs].MIN);
	}
	int change(int x,int l,int r,int wh,int v)
	{
		if (!x) x=++cnt;
		if (l==r)
		{
			sh[x].sum+=v;
			sh[x].MIN=l;
			return x;
		}
		int mid=(l+r)>>1;
		if (wh<=mid) sh[x].ls=change(sh[x].ls,l,mid,wh,v);
		else sh[x].rs=change(sh[x].rs,mid+1,r,wh,v);
		pushup(x);return x;
	}
}
void upd(int x,int y)
{
	s.erase(m_k(d[x],x));
	int t=lower_bound(e[x].begin(),e[x].end(),m_k(y,0))-e[x].begin();
	t=e[x][t].second;
	seg::change(rt[x],0,n+m+1,n+m+1,-t);
	rt[x]=seg::change(rt[x],0,n+m+1,d[y],t);
	d[x]=seg::sh[rt[x]].MIN+1;
	s.insert(m_k(d[x],x));
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		dg[u]++;
		p[u].push_back(v);E[v].push_back(u);
	}
	seg::init();
	for (int i=1;i<=n;i++) 
	{
		sort(p[i].begin(),p[i].end());
		sort(E[i].begin(),E[i].end());
		E[i].resize(unique(E[i].begin(),E[i].end())-E[i].begin());
		for (int j=0;j<len(p[i]);)
		{
			int k=j;
			while (p[i][j]==p[i][k]&&k<len(p[i])) k++;
			e[i].emplace_back(p[i][j],k-j);
			j=k;
		}
		for (auto [u,w]:e[i]) rt[i]=seg::change(rt[i],0,n+m+1,n+m+1,w);
		d[i]=n+m+1;
	}
	d[n]=0;
	for (int i=1;i<=n;i++) s.insert(m_k(d[i],i));
	while (!s.empty())
	{
		int x=(*s.begin()).second;s.erase(s.begin());
		vi[x]=1;
		for (int u:E[x]) if (!vi[u]) 
			upd(u,x);
	}
	printf("%d\n",d[1]);
}