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
	int a[N],pre[N],suf[N];
	int st[N],top;
	int tl[N],tr[N];
	struct segmengt
	{
		int ans[N<<2];
		inline void update(int pos,int l,int r,int p,int k)
		{
			if(l==r)
			{
				ans[p]=k;
				return;
			}
			if(pos<=mid) update(pos,l,mid,ls(p),k);
			if(pos>mid) update(pos,mid+1,r,rs(p),k);
			ans[p]=max(ans[ls(p)],ans[rs(p)]);
		}
		inline int query(int tl,int tr,int l,int r,int p)
		{
			if(tl<=l&&r<=tr) return ans[p];
			int sum=-inf*inf;
			if(tl<=mid) sum=max(sum,query(tl,tr,l,mid,ls(p)));
			if(tr>mid) sum=max(sum,query(tl,tr,mid+1,r,rs(p)));
			return sum;
		}
	}T[2];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		int skx;cin>>skx;
		while(skx--)
		{
			cin>>n;
			for(int i=1;i<=n;++i)
			{
				cin>>a[i];
				pre[i]=pre[i-1]+a[i];
				T[0].update(i,1,n,1,pre[i]);
			}
			suf[n+1]=0;
			for(int i=n;i>=1;--i)
			{
				suf[i]=suf[i+1]+a[i];
				T[1].update(i,1,n,1,suf[i]);
			}
			top=0;
			for(int i=1;i<=n;++i)
			{
				while(top>0&&a[i]>a[st[top]])
				{
					tr[st[top--]]=i-1;
				}
				st[++top]=i;
			}
			while(top) tr[st[top--]]=n;
			for(int i=n;i>=1;--i)
			{
				while(top>0&&a[i]>a[st[top]])
				{
					tl[st[top--]]=i+1;
				}
				st[++top]=i;
			}
			while(top) tl[st[top--]]=1;
			bool flag=0;
			for(int i=1;i<=n;++i)
			{
				int l=tl[i],r=tr[i];
				int pr=T[0].query(i,r,1,n,1)-pre[i];
				int pl=T[1].query(l,i,1,n,1)-suf[i];
				if(pr+pl>0) flag=1;
			}
			if(flag) cout<<"NO\n";
			else cout<<"YES\n";
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
3 -1 3 -1 3
*/