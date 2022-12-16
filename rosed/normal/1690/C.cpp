#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=1e9+7;
	int n;
	int a[N],b[N],d[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			for(int i=1;i<=n;++i) cin>>a[i];
			for(int i=1;i<=n;++i) cin>>b[i];
			int now=0;
			for(int i=1;i<=n;++i)
			{
				now=max(now,a[i]);
				d[i]=b[i]-now;
				now=max(now,b[i]);
				cout<<d[i]<<" \n"[i==n];
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}

/*
5
1 2 300
1 3 1
1 4 499
2 5 300
3
3 2 5

*/