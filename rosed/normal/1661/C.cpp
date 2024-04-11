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
	inline bool check(int x,int y)
	{
		int s1=(x+1)/2,s2=x/2;
		for(int i=1;i<=n;++i)
		{
			b[i]=y-a[i];
			if(b[i]&1) --s1,--b[i];
		}
		for(int i=1;i<=n;++i)
		{
			int tmp=min(b[i]/2,s2);
			b[i]-=2*tmp;
			s2-=tmp;
			s1-=b[i];
		}
		return s1>=0&&s2>=0;
	}
	inline int work(int x)
	{
		int l=0,r=1e15;
		while(l<=r)
		{
			if(check(mid,x)) r=mid-1;
			else l=mid+1;
		}
		return r+1;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;ans=inf;
			for(int i=1;i<=n;++i) cin>>a[i];
			sort(a+1,a+n+1);
			ans=min(work(a[n]),work(a[n]+1));
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