#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=2e9;
	int n,x;
	int ans=inf;
	int a[N];
	inline int check(int x)
	{
		int sum=0;
		while(x) ++sum,x/=10;
		return sum;
	}
	inline void dfs(int num,int len)
	{
		if(len>=ans) return;
		int pos=check(num);
		if(len+(n-pos)>=ans) return;
		if(pos>n) return;
		if(pos==n)
		{
			ans=min(ans,len);
			return;
		}
		vector<int> vis(10);
		int x=num;
		while(x)
		{
			vis[x%10]=1,x/=10;
		}
		for(int c=9;c>1;--c) if(vis[c])
		{
			dfs(num*c,len+1);
		}
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n>>x;
		dfs(x,0);
		if(ans>=inf) cout<<"-1\n";
		else cout<<ans<<'\n';
		//cout<<dfs(x)<<'\n';
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