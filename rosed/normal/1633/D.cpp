#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define eps (1e-8)
	const int N=1e6+10,mod=998244353;
	int n,k;
	int a[N];
	int w[N];
	int g[N];
	int f[N];
	struct node
	{
		int b,c;
		inline bool operator < (const node &t) const
		{
			return b<t.b;
		}
	}q[N];
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		memset(g,0x3f,sizeof(g));
		g[1]=0;
		for(int i=1;i<=1000;++i)
		{
			for(int k=1;k<=i;++k)
			{
				int tmp=i/k;
				g[i+tmp]=min(g[i+tmp],g[i]+1);
			}
		}
		while(T--)
		{
			cin>>n>>k;
			for(int i=1;i<=n;++i) a[i]=1;
			for(int i=1;i<=n;++i) {cin>>q[i].b;q[i].b=g[q[i].b];}
			for(int i=1;i<=n;++i) cin>>q[i].c;
			sort(q+1,q+n+1);
			for(int i=0;i<=k;++i) f[i]=0;
			int tot=0,ans=0;
			for(int i=1;i<=n;++i)
			{
				tot+=q[i].b;
				tot=min(tot,k);
				for(int j=tot;j>=q[i].b;--j)
				{
					f[j]=max(f[j],f[j-q[i].b]+q[i].c);
					ans=max(ans,f[j]);
				}
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