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
	int s[N];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			int minn=0,len=min(n,m);
			int ans=0,tmp=0;
			if(m>=n) ans=((m-n)+(m-1))*n/2;
			else ans=m*(m-1)/2;
			//cout<<ans<<"!!"<<endl;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				s[i]=s[i-1]+a[i];
				if(i>=len) tmp=max(tmp,s[i]-s[i-len]);
			}
			cout<<ans+tmp<<'\n';
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
5 7
5 6 1 2 3


12+3+5+7
27
*/