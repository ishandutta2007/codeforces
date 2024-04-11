#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
struct union_set
{
	vector<int> f;
	int n;
	union_set(){}
	union_set(int nn):n(nn),f(nn+1)
	{
		iota(all(f),0);
	}
	int getf(int u) {return f[u]==u?u:f[u]=getf(f[u]);}
	void uni(int u,int v)
	{
		u=getf(u);v=getf(v);
		f[u]=v;
	}
	bool con(int u,int v) {return getf(u)==getf(v);}
};
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i;
		cin>>n>>m;
		union_set s(n+1);
		vector<ll> a(n+1);
		vector<int> deg(m,2),b(n+1);
		vector<pair<int,int>> p(m);
		vector<vector<int>> e(n+1);
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) cin>>b[i];
		for (i=0;i<m;i++)
		{
			auto &[l,r]=p[i];
			cin>>l>>r;
			e[l-1].push_back(i);
			e[r].push_back(i);
		}
		for (i=1;i<=n;i++) a[i]-=b[i];
		for (i=1;i<=n;i++) a[i]+=a[i-1];
		queue<int> q;
		for (i=0;i<=n;i++) if (!a[i]) q.push(i),s.uni(i,i+1);
		while (q.size())
		{
			int x=q.front();q.pop();
			for (int y:e[x]) if (!--deg[y])
			{
				auto [l,r]=p[y];
				if (s.getf(l)==s.getf(r+1)) continue;
				int L=l;
				while (l<r)
				{
					if (a[l]) a[l]=0,q.push(l);
					if (l<s.f[l]) l=s.f[l]; else s.f[l]=l+1,++l;
				}
				s.uni(L,r+1);
			}
		}
		cout<<(s.con(0,n+1)?"Yes\n":"No\n");
	}
}