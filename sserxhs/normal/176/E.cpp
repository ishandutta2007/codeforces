#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Q
{
	int v,w;
	Q(int a,int b):v(a),w(b){}
};
const int N=1e5+2;
ll dep[N],ans;
vector<Q> lj[N];
int dfn[N],f[N],top[N],siz[N],hc[N];
int n,q,i,x,y,z;
char c;
struct cmp
{
	bool operator()(const int &x,const int &y) const {return dfn[x]<dfn[y];}
};
set<int,cmp> s;
void dfs1(int u)
{
	dfn[u]=++q;siz[u]=1;
	for (auto &[v,w]:lj[u]) if (v!=f[u])
	{
		dep[v]=dep[f[v]=u]+w;
		dfs1(v);siz[u]+=siz[v];
		if (siz[v]>siz[hc[u]]) hc[u]=v;
	}
}
void dfs2(int x)
{
	if (hc[x])
	{
		top[hc[x]]=top[x];
		dfs2(hc[x]);
		for (auto &[v,w]:lj[x]) if (v!=f[x]&&v!=hc[x]) dfs2(top[v]=v);
	}
}
int lca(int x,int y)
{
	while (top[x]^top[y]) if (dep[top[x]]>dep[top[y]]) x=f[top[x]]; else y=f[top[y]];
	return dep[x]<dep[y]?x:y;
}
ll dis(int x,int y)
{
	return dep[x]+dep[y]-(dep[lca(x,y)]<<1);
}
auto pre(set<int>::iterator it)
{
	if (it==s.begin()) return --s.end();
	return --it;
}
auto nxt(set<int>::iterator it)
{
	++it;
	if (it==s.end()) return s.begin();
	return it;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y>>z;
		lj[x].emplace_back(y,z);
		lj[y].emplace_back(x,z);
	}
	dfs1(dep[1]=1);dfs2(top[1]=1);
	cin>>q;
	while (q--)
	{
		cin>>c;
		if (c=='?') cout<<(ans>>1)<<'\n';
		else
		{
			cin>>x;
			if (c=='+')
			{
				assert(s.find(x)==s.end());
				auto it=s.insert(x).first;
				auto jt=pre(it),kt=nxt(it);
				ans+=dis(*it,*jt)+dis(*it,*kt)-dis(*jt,*kt);
			}
			else if (c=='-')
			{
				assert(s.find(x)!=s.end());
				auto it=s.find(x);
				auto jt=pre(it),kt=nxt(it);
				ans-=dis(*it,*jt)+dis(*it,*kt)-dis(*jt,*kt);
				s.erase(it);
			}
		}
	}
}