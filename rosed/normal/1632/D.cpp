#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	const int N=3e5+10,mod=998244353;
	int n,m,ans,l;
	int a[N];
	struct seg
	{
		int ans[N<<2];
		inline void build(int l,int r,int p)
		{
			if(l==r)
			{
				ans[p]=a[l];
				return;
			}
			build(l,mid,ls(p));
			build(mid+1,r,rs(p));
			ans[p]=__gcd(ans[ls(p)],ans[rs(p)]);
		} 
		inline int query(int tl,int tr,int l,int r,int p)
		{
			if(tl<=l&&r<=tr) return ans[p];
			if(tl>mid) return query(tl,tr,mid+1,r,rs(p));
			if(tr<=mid) return query(tl,tr,l,mid,ls(p));
			return __gcd(query(tl,tr,l,mid,ls(p)),query(tl,tr,mid+1,r,rs(p)));
		}
	}T;
	inline bool check(int l,int r)
	{
		int pos=r,rr=r;
		while(l<=r)
		{
			if(T.query(mid,rr,1,n,1)<=rr-mid+1) pos=mid,l=mid+1;
			else r=mid-1;
		}
		return T.query(pos,rr,1,n,1)==rr-pos+1;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		T.build(1,n,1);
		l=1;
		for(int i=1;i<=n;++i)
		{
			if(check(l,i)) ++ans,l=i+1;
			cout<<ans<<" \n"[i==n];
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