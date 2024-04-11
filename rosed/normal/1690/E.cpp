#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,inf=1e9+7;
	int n,m;
	int a[N];
	queue<int> q[1010];
	int f[N];
	inline int find(int k){return f[k]==k?k:f[k]=find(f[k]);}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			int ans=0;
			for(int i=0;i<m;++i)
			{
				while(!q[i].empty()) q[i].pop();
				f[i]=i;
			}
			f[m]=m;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				int k=a[i]%m;
				int t=(m-k)%m;
				if(!q[t].empty())
				{
					int x=q[t].front();
					q[t].pop();
					ans+=(a[i]+x)/m;
				}
				else q[k].push(a[i]);
			}
			for(int i=0;i<m;++i)
			{
				if(q[i].empty()) f[find(i)]=find(i+1);
			}
			for(int i=0;i<m;i=find(i+1))
			{
				for(int j=max(i+1,m-i);j<m;j=find(j+1))
				{
					while(!q[i].empty()&&!q[j].empty())
					{
						int x=q[i].front(),y=q[j].front();
						ans+=(x+y)/m;
						q[i].pop(),q[j].pop();
					}
					if(q[j].empty()) f[find(j)]=find(j+1);
				}
				if(q[i].empty()) f[find(i)]=find(i+1);
			}
			int pre=-1;
			for(int i=0;i<m;i=find(i+1))
			{
				while(!q[i].empty())
				{
					int x=q[i].front();
					q[i].pop();
					if(pre==-1) pre=x;
					else ans+=(pre+x)/m,pre=-1;
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
5
1 2 300
1 3 1
1 4 499
2 5 300
3
3 2 5

*/