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
	int a[N],s[N];
	bool vis[N];
	typedef pair<int,int> pr;
	priority_queue<pr> q;
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			while(!q.empty()) q.pop();
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				q.push(pr(a[i]+i,i));
				vis[i]=1;
			}
			while(m--)
			{
				int pos=q.top().second;
				q.pop();
				vis[pos]=0;
			}
			int ans=0;
			for(int i=1;i<=n;++i)
			{
				s[i]=s[i-1]+(!vis[i]);
				if(vis[i]) ans+=a[i]+s[i];
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

1
4 1
5 10 11 5


10
4 4
8 7 1 4
4 1
5 10 11 5
7 5
8 2 5 15 11 2 8
6 3
1 2 3 4 5 6
1 1
7
4 4
8 7 1 4
4 1
5 10 11 5
7 5
8 2 5 15 11 2 8
6 3
1 2 3 4 5 6
1 1
7

*/