#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n,ans,sum,pre;
	int a[N];
	inline void work(int len)
	{
		sum=n-len;
		int tot=len;
		while(tot<n) tot<<=1,++sum;
		ans=min(ans,sum);
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;ans=inf;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			pre=1;
			sort(a+1,a+n+1);
			for(int i=1;i<=n;++i)
			{
				if(a[i]==a[pre]) continue;
				work(i-pre);
				pre=i;
			}
			work(n-pre+1);
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

*/