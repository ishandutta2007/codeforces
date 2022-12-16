#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n,ans;
	int a[N],b[N];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;ans=0;
			for(int i=1;i<=n;++i) cin>>a[i];
			for(int i=1;i<=n;++i) cin>>b[i];
			for(int i=1;i<n;++i)
			{
				ans+=min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]),abs(a[i]-b[i+1])+abs(b[i]-a[i+1]));
			}
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
10
4
5
6
7
8
9
10
11
12
13

*/