#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=3e5+10,mod=1e9+7,inf=INT_MAX;
	int n,k;
	int a[N],c[N];
	int rr[N];
	int pre[N],suf[N];
	int ans[N<<2];
	inline void build(int l,int r,int p)
	{
		if(l==r)
		{
			ans[p]=rr[l];
			return;
		}
		build(l,mid,ls(p));
		build(mid+1,r,rs(p));
		ans[p]=max(ans[ls(p)],ans[rs(p)]);
	}
	inline int query(int tl,int tr,int l,int r,int p)
	{
		if(tl<=l&&r<=tr) return ans[p];
		int sum=0;
		if(tl<=mid) sum=max(sum,query(tl,tr,l,mid,ls(p)));
		if(tr>mid) sum=max(sum,query(tl,tr,mid+1,r,rs(p)));
		return sum;
	}
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=n;++i)
		{
			if(!pre[a[i]]) pre[a[i]]=i;
			else suf[a[i]]=i;
		}
		for(int i=1;i<=n;++i)
		{
			if(i!=pre[a[i]]) continue;
			rr[i]=suf[a[i]];
		}
		build(1,n,1);
		int ans=0;
		int rrr=0;
		for(int i=1;i<=n;++i)
		{
			if(i!=pre[a[i]]) continue;
			if(pre[a[i]]+1>=suf[a[i]]) continue;
			ans+=suf[a[i]]-(pre[a[i]]+1);rrr=suf[a[i]]+1;
			int maxr=query(pre[a[i]]+1,suf[a[i]],1,n,1);
		//	cout<<suf[a[i]]<<' '<<pre[a[i]]+1<<"!!"<<endl;
		//	cout<<rr[3]<<"!!!!"<<endl;
			while(maxr>=rrr)
			{
				ans+=maxr-rrr;
			//	cout<<maxr<<' '<<rrr<<"!!!!!!!!!!!!!!!!!!!!"<<endl;
				rrr=maxr+1; 
				maxr=query(pre[a[i]]+1,maxr,1,n,1);
			}
			i=rrr-1;
		}
		cout<<ans<<'\n';
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