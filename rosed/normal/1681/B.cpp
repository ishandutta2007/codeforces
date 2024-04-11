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
	int a[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			int pos=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			cin>>m;
			for(int i=1;i<=m;++i)
			{
				int x;cin>>x;
				pos=(pos+x)%n;
			}
			cout<<a[pos+1]<<'\n';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
212
*/