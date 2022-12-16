#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;
			if(!n)
			{
				cout<<"0 ";
				continue;
			}
			int ans=0,ret=inf;
			while(lowbit(n)!=n)
			{
				int tmp=lowbit(n),s=ans;
				while(tmp<(1<<15)) tmp<<=1,++s;
				ret=min(ret,s);
				ans+=lowbit(n);
				n+=lowbit(n);
			}
			while(n<(1<<15)) n<<=1,++ans;
			ret=min(ret,ans);
			cout<<ret<<' ';
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
10011

*/