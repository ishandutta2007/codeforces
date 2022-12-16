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
	int a[N],num;
	vector<int> eg[N];
	int st[N],top;
	inline void dfs(int now,int fa)
	{
		int sum=0;
		for(int t:eg[now])
		{
			if(t==fa) continue;
			dfs(t,now);
			++sum;
		}
		if(sum) st[++top]=sum;
	}
	inline bool cmp(int a,int b)
	{
		return a>b;
	}
	inline bool check(int x)
	{
		int tot=0;
		for(int i=1;i<=top;++i)
		{
			++tot;
			a[i]=st[i]-1-(x-i);
			if(a[i]<=0) continue;
			tot+=a[i];
		}
		return tot<=x;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;top=0;
			st[++top]=1;ans=0;
			for(int i=1;i<=n;++i) eg[i].clear();
			for(int i=2;i<=n;++i)
			{
				int fa;cin>>fa;
				eg[fa].push_back(i);
				eg[i].push_back(fa);
			}
			dfs(1,0);
			sort(st+1,st+top+1,cmp);
			int l=top,r=n;
			while(l<=r)
			{
				//cout<<mid<<"!!!!!!!!!!!!!!!"<<endl;
				if(check(mid)) r=mid-1;
				else l=mid+1;
			}
			cout<<r+1<<'\n';
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
6
1 1 1 1 1

*/