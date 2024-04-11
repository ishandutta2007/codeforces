#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10;
	int n,m;
	int a[N];
	typedef pair<int,int> pr;
	pr p[N];
	vector<int> eg[N];
	set<int> s;
	int f[N];
	inline find(int k){return f[k]==k?k:f[k]=find(f[k]);}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			++n;
			for(int i=1;i<=n;++i)
			{
				f[i]=i;
				eg[i].clear();
			}
			for(int i=2;i<=n;++i) cin>>a[i];
			for(int i=2;i<=n;++i)
			{
				int x;cin>>x;
				a[i]-=x;
			}
			for(int i=2;i<=n;++i) a[i]+=a[i-1];
			for(int i=1;i<=m;++i)
			{
				auto &[l,r]=p[i];
				cin>>l>>r;
				++l,++r;
				eg[l-1].emplace_back(r);
				eg[r].emplace_back(l-1);
			}
			queue<int> q;
			set<int> s;
			for(int i=1;i<=n;++i)
			{
				if(a[i]) s.insert(i);
				else q.push(i);
			}
			while(!q.empty())
			{
				int now=q.front();q.pop();
				for(int t:eg[now])
				{
					if(a[t]) continue;
					int l=min(now,t),r=max(now,t);
					auto it=s.lower_bound(l);
					while(it!=s.end()&&(*it)<=r)
					{
						int p=*it;
						a[p]=0;
						q.push(p);
						auto it1=it;++it;
						s.erase(it1);
					}
				}
			}
			if(s.empty()) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
1
10 5
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 3
3 5
5 7
7 9
9 10

-1 1 -1 1 -1 1 -1 1 -1 1


*/