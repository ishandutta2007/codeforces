#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	int n,m;
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			vector<vector<int> > a(n,vector<int>(m));
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<m;++j) cin>>a[i][j];
			}
			int x=0;
			while(x<n&&is_sorted(a[x].begin(),a[x].end())) ++x;
			if(x==n)
			{
				cout<<1<<' '<<1<<'\n';
				continue;
			}
			auto b=a[x];
			sort(b.begin(),b.end());
			vector<int> p;
			for(int i=0;i<m;++i)
			{
				if(a[x][i]!=b[i]) p.emplace_back(i);
			}
			if(p.size()>2)
			{
				cout<<"-1\n";
				continue;
			}
			bool flag=0;
			for(int i=0;i<n&&!flag;++i)
			{
				swap(a[i][p[0]],a[i][p[1]]);
				if(!is_sorted(a[i].begin(),a[i].end()))
				{
					cout<<"-1\n";
					flag=1;
				}
			}
			if(!flag) cout<<p[0]+1<<' '<<p[1]+1<<'\n';
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
1 7
1 2 4 3 3 3 5

*/