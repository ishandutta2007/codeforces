#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
	const int N=5e5+10,mod=1e9+7,inf=INT_MAX;
	int n,m,ret;
	int a[N],b[N],c[N];
	int tr[N];
	struct segment_tree
	{
		int ans[N<<2],tag[N<<2];
		inline void pushdown(int l,int r,int p)
		{
			ans[ls(p)]+=(mid-l+1)*tag[p];
			ans[rs(p)]+=(r-mid)*tag[p];
			tag[ls(p)]+=tag[p];
			tag[rs(p)]+=tag[p];
			tag[p]=0;
		}
		inline void update(int tl,int tr,int l,int r,int p,int k)
		{
			//cout<<l<<' '<<r<<' '<<tl<<' '<<tr<<"!!"<<endl;
			if(tl<=l&&r<=tr)
			{
				ans[p]+=k*(r-l+1);
				tag[p]+=k;
				return;
			}
			if(tag[p]) pushdown(l,r,p);
			if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
			if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
			ans[p]=ans[ls(p)]+ans[rs(p)];
		}
		inline int query(int tl,int tr,int l,int r,int p)
		{
			if(tl<=l&&r<=tr) return ans[p];
			if(tag[p]) pushdown(l,r,p);
			int sum=0;
			if(tl<=mid) sum+=query(tl,tr,l,mid,ls(p));
			if(tr>mid) sum+=query(tl,tr,mid+1,r,rs(p));
			return sum;
		}
	}T;
	inline void main()
	{
		ios::sync_with_stdio(false);
		cin.tie(0);cout.tie(0);
		int TT;TT=1;
		while(TT--)
		{
			cin>>n>>m;ret=0;
			for(int i=1;i<=n;++i)
			{
				cin>>b[i];
				c[i]=b[i];	
			}
			for(int i=n;i-m+1>=1;--i)
			{
				int sum=T.query(1,i,1,n,1);
				if(sum<c[i])
				{
					int tmp=(c[i]-sum-1)/m+1;
					T.update(i-m+1,i,1,n,1,tmp);
					if(i+1<=n) T.update(i+1,i+1,1,n,1,-m*tmp);
					ret+=tmp;
				}
			}
			for(int i=m-1;i>=1;--i)
			{
				int sum=T.query(1,i,1,n,1);
				//cout<<i<<' '<<sum<<"!!"<<endl;
				if(sum<c[i])
				{
					int tmp=(c[i]-sum-1)/i+1;
					T.update(1,m,1,n,1,tmp);
					if(m+1<=n) T.update(m+1,m+1,1,n,1,-m*tmp);
					ret+=tmp;
				}
			}
			cout<<ret<<'\n';	 
			//3 4 5
				//5-3+1
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
10
4
5
6
7
8
9
10
11
12
13

*/