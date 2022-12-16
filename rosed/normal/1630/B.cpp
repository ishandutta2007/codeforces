#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n,k;
	int ansl,ansr,top;
	int a[N];
	int tr[N];
	typedef pair<int,int> p;
	p st[N];
	inline void update(int x)
	{
		for(int i=x;i<=n;i+=lowbit(i)) ++tr[i];
	}
	inline int query(int x)
	{
		int sum=0;
		for(int i=x;i;i-=lowbit(i)) sum+=tr[i];
		return sum;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int T;cin>>T;
		while(T--)
		{
			cin>>n>>k;
			int minn=n-n/2;
			while(minn-(n-minn)<k) ++minn;
			for(int i=1;i<=n;++i) a[i]=tr[i]=0;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				update(a[i]);
			}
			int ans=n;
			ansl=1,ansr=n;
			int l=n;
			for(int r=n;r>=1;--r)
			{
				while(l>=1&&query(r)-query(l-1)<minn) --l;
				if(l>0&&query(r)-query(l-1)>=minn)
				{
					if(r-l+1<=ans) ans=r-l+1,ansr=r,ansl=l;
				}
			}
			int sum=0;top=0;
			int pre=1;
			for(int i=1;i<=n;++i)
			{
				if(top==k-1)
				{
					st[++top]=p(pre,n);break;
				}
				sum+=(ansl<=a[i]&&a[i]<=ansr)?1:-1;
				if(sum>0)
				{
					st[++top]=p(pre,i);pre=i+1;
					sum=0;
				}
			}
			cout<<ansl<<' '<<ansr<<'\n';
			for(int i=1;i<=top;++i)
			{
				cout<<st[i].first<<' '<<st[i].second<<'\n';
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
1
8
1 3 2 4 7 5 6 8

*/