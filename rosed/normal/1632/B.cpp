#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	const int N=3e5+10,mod=998244353;
	int n,m;
	int st[N],top;
	bool vis[N];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n;--n;
			int len=0;top=0;
			while(1<<(len+1)<=n) ++len;
			int ans=1<<len;
			for(int i=0;i<=n;++i) vis[i]=0;
			for(int i=n;i>=ans;--i)
			{
				st[++top]=i;
			}
			st[++top]=0;
			for(int i=1;i<=top;++i) vis[st[i]]=1;
			for(int i=0;i<=n;++i)
			{
				if(vis[i]) continue;
				else st[++top]=i;
			}
			for(int i=1;i<=top;++i)
			{
				cout<<st[i]<<" \n"[i==top];
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
5 7
1 2 3 4 5
1 1 5
2 1 5

3 1 2 1
1 1 4
4 1 3 2
1 1 4
2 2 3

*/