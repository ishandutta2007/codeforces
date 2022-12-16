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
	int a[N],b[N];
	bool vis[N];
	map<int,int> q;
	int st[N],top;
	inline bool check(int x)
	{
		for(int i=1;i<=n;++i) b[i]=a[i];
		for(int i=0;i<x;++i) vis[i]=0;
		int sum=0;
		for(int i=1;i<=n;++i)
		{
			if(b[i]<x)
			{
				if(!vis[b[i]]) vis[b[i]]=1;
				else ++sum;
			}
			else ++sum;
		}
		
		sum=min(sum,m);
		for(int i=0;i<x;++i)
		{
			if(!vis[i]) --sum;
		}
		return sum>=0;
	}
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n>>m;
			top=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}

			sort(a+1,a+n+1);
			int l=0,r=n,mex=0;
			while(l<=r)
			{
				if(check(mid)) mex=mid,l=mid+1;
				else r=mid-1;
			}
			for(int i=0;i<mex;++i) vis[i]=0;
			q.clear();
			for(int i=1;i<=n;++i)
			{
				if(a[i]<mex) vis[a[i]]=1;
				else ++q[a[i]];
			}
			for(auto tmp:q)
			{
				st[++top]=tmp.second;
			}
			sort(st+1,st+top+1);
			int t=1;
			while(m>0&&t<=top)
			{
				if(st[t]>m) break;
				m-=st[t++];
			}
			cout<<top-t+1<<'\n';
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
3 1
1 1 1

*/