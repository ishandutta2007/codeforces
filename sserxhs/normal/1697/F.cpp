//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC> istream & operator>>(istream &in,vector<typC> &a)
{
	for (auto &x:a) cin>>x;
	return cin;
}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
	for (auto &x:a) cout<<x<<'\n';
	return cout;
}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a)
{
	int n=a.size(),i;
	if (!n) return cout;
	cout<<a[0];
	for (i=1;i<n;i++) cout<<' '<<a[i];
	return cout;
}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=8e5;
struct sat
{
	vector<vector<int>> e;
	vector<int> dfn,low,st,f,ed;
	int fs,tp,id,n;
	sat(int n):n(n),e(n*2),dfn(n*2,-1),low(n*2),st(n*2),f(n*2,-1),ed(n*2),fs(0),tp(-1),id(0){}
	void dfs(int u)
	{
		dfn[u]=low[u]=id++;
		ed[u]=1;st[++tp]=u;
		for (int v:e[u]) if (~dfn[v])
		{
			if (ed[v]) low[u]=min(low[u],dfn[v]);
		} else dfs(v),low[u]=min(low[u],low[v]);
		if (dfn[u]==low[u])
		{
			do
			{
				f[st[tp]]=fs;
				ed[st[tp]]=0;
			} while (st[tp--]!=u);
			++fs;
		}
	}
	void add(int u,bool x,int v,bool y)//d:dif
	{
		assert(u>=0&&u<n&&v>=0&&v<n);
		e[u+x*n].push_back(v+y*n);
		e[v+(y^1)*n].push_back(u+(x^1)*n);
	}
	void set(int u,bool x)
	{
		assert(u>=0&&u<n);
		e[u+(x^1)*n].push_back(u+x*n);
	}
	vector<int> getans()
	{
		int i;
		for (i=0;i<n*2;i++) if (dfn[i]==-1) dfs(i);
		vector<int> r(n);
		for (i=0;i<n;i++)
		{
			if (f[i]==f[i+n]) return {};
			r[i]=f[i]>f[i+n];
		}
		return r;
	}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;cin>>T;
	while (T--)
	{
		int n,m,q,i,j;
		cin>>n>>m>>q;
		sat s(n*q*2);
		for (i=0;i<n;i++)
		{
			for (j=1;j<q;j++)
			{
				s.add(i*q*2+j-1,1,i*q*2+j,1);
				s.add(i*q*2+j+q,1,i*q*2+j+q-1,1);
				s.add(i*q*2+j-1,1,i*q*2+j+q,0);
				s.add(i*q*2+j-1,0,i*q*2+j+q,1);
			}
			s.set(i*q*2+q-1,1);s.set(i*q*2+q,1);
		}
		for (i=1;i<n;i++)
		{
			for (j=0;j<q;j++)
			{
				s.add(i*q*2+j,1,(i-1)*q*2+j,1);
				s.add((i-1)*q*2+q+j,1,i*q*2+q+j,1);
			}
		}
		while (m--)
		{
			int op,x,y;
			cin>>op>>x>>y;
			--x;--y;
			if (op==1)
			{
				if (y) s.add(x*q*2+y,1,x*q*2+y-1,1); else s.set(x*q*2,0);
				if (y<q-1) s.add(x*q*2+q+y,1,x*q*2+q+y+1,1); else s.set(x*q*2+q*2-1,0);
			}
			else
			{
				int z;
				cin>>z;z-=2;
				int R=min(q-1,z);
				if (op==2)
				{
					for (i=max(0,z-q+1);i<=R;i++)
					{
						s.add(x*q*2+q+i,1,y*q*2+(z-i),1);
						s.add(y*q*2+q+i,1,x*q*2+(z-i),1);
					}
				}
				else
				{
					for (i=max(0,z-q+1);i<=R;i++)
					{
						s.add(x*q*2+i,1,y*q*2+q+(z-i),1);
						s.add(y*q*2+i,1,x*q*2+q+(z-i),1);
					}
				}
			}
		}
		auto r=s.getans();
		if (!r.size()) cout<<"-1\n"; else for (i=0;i<n;i++) cout<<find(i*q*2+all(r),1)-r.begin()-i*q*2+1<<" \n"[i+1==n];
	}
}