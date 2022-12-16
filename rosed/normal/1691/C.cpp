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
	char s[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			cin>>(s+1);
			if(n==1)
			{
				cout<<0<<'\n';
				continue;
			}
			int ans=0;
			int t1=inf,t2=-inf;
			for(int i=1;i<=n;++i)
			{
				if(s[i]=='1')
				{
					if(t1==inf) t1=i;
					t2=i;
					ans+=11;
				}
			}
			bool ok=0;
			if(n-t2<=m) ok=1,m-=(n-t2),ans-=10;
			if((t1!=t2||!ok)&&m>=t1-1) m-=t1-1,ans--;
			cout<<ans<<'\n';
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
4 0
1010
7 2
0010100
5 2
00110
2 0
10
5 5
11010

*/