/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define del(a,b) a.erase(a.lower_bound(b))
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int n,m,q;
unordered_map <int,int> mp[N];
struct node
{
	int u,v,w;
};
bool operator ==(node a,node b){return a.u==b.u&&a.v==b.v&&a.w==b.w;}
bool operator <(node a,node b)
{
	if (a.w!=b.w) return a.w<b.w;
	return a.u<b.u||(a.u==b.u&&a.v<b.v);
}
multiset <node> s[N];
set <node> e;
multiset <int> all;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
inline bool check(node a,node b){return (a.u==b.u||a.u==b.v||a.v==b.u||a.v==b.v);}
inline int sum(multiset <node> &s)
{
	if (len(s)<3) return inf;
	auto it=s.begin();int ans=0;
	ans+=(*it).w;it++;
	ans+=(*it).w;it++;
	ans+=(*it).w;return ans;
}
inline bool in(multiset <node> &s,node x)
{
	int k=1;
	for (auto it=s.begin();it!=s.end()&&k!=3;it++,k++) if (x==*it) return 1;
	return 0;
}
inline void upd(int x,int op)//upd e
{
	int k=1;
	for (auto it=s[x].begin();it!=s[x].end()&&k!=3;it++,k++)
	{
		node now=*it;bool bl;
		bl=((now.u==x)?in(s[now.v],now):in(s[now.u],now));
		if (!bl) continue;
		if (op==1) e.insert(now);
		else
		{
			auto tmp=e.lower_bound(now);
			if (*tmp==now) e.erase(tmp);
		}
	}
}
inline void add_edge(int u,int v,int w)
{
	if (u>v) swap(u,v);
	mp[u][v]=mp[v][u]=w;
	node x=(node){u,v,w};
	upd(u,0);upd(v,0);
	del(all,sum(s[u]));del(all,sum(s[v]));
	s[u].insert(x);s[v].insert(x);
	all.insert(sum(s[u]));all.insert(sum(s[v]));
	upd(u,1);upd(v,1);
}
inline void del_edge(int u,int v)
{
	int w=mp[u][v];mp[u][v]=mp[v][u]=0;
	if (u>v) swap(u,v);
	node x=(node){u,v,w};
	upd(u,0);upd(v,0);
	del(all,sum(s[u]));del(all,sum(s[v]));
	del(s[u],x);del(s[v],x);
	all.insert(sum(s[u]));all.insert(sum(s[v]));
	upd(u,1);upd(v,1);
}
inline int solve(multiset <node> &a,multiset <node> &b)
{
	if (a.empty()||b.empty()) return inf;
	node x=*a.begin(),y=*b.begin();
	if (!check(x,y)) return x.w+y.w;
	int ans=inf;
	auto it=a.begin();it++;
	if (it!=a.end()&&!check(*it,y)) ans=min(ans,(*it).w+y.w);
	it=b.begin();it++;
	if (it!=b.end()&&!check(*it,x)) ans=min(ans,x.w+(*it).w);
	return ans;
}
inline int getans()
{
	node x=(*e.begin());
	auto it=e.begin();it++;int k=0;
	for (;it!=e.end();it++,k++) if (!check(*it,x)) break;
	assert(k<=20);
	int ans=(*all.begin());
	if (it!=e.end())
	{
		// assert(mp[(*it).u][(*it).v]!=0&&mp[x.u][x.v]!=0);
		ans=min(ans,(*it).w+x.w);
	}
	del(s[x.u],x);del(s[x.v],x);
	ans=min(ans,solve(s[x.u],s[x.v]));
	s[x.u].insert(x);s[x.v].insert(x);
	return ans;
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) all.insert(sum(s[i]));
	for (int i=1;i<=m;i++) 
	{
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}
	// for (auto it:e) printf("%lld %lld %lld\n",it.u,it.v,it.w);
	printf("%lld\n",getans());
	q=read();
	while (q--)
	{
		int op=read();
		if (op==1)
		{
			int u=read(),v=read(),w=read();
			add_edge(u,v,w);
		}
		else
		{
			int u=read(),v=read();
			del_edge(u,v);
		}
		// assert(len(e)<=3*n);
		printf("%lld\n",getans());
	}
}