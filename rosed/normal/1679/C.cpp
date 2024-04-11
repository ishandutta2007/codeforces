#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define lowbit(i) ((i)&(-i))
#define y1 qwq
	inline int read()
	{
		int x=0;char f=0,ch;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=2e5+10;
	int n,m;
	int a[N];
	struct BIT
	{
		int ans[N<<2];
		bool vis[N<<2];
		inline void update(int pos,int l,int r,int p,int k)
		{
			if(l==r)
			{
				ans[p]+=k;
				if(ans[p]>0) vis[p]=1;
				else vis[p]=0;
				return;
			}
			if(pos<=mid) update(pos,l,mid,ls(p),k);
			else update(pos,mid+1,r,rs(p),k);
			vis[p]=vis[ls(p)]&vis[rs(p)];
		}
		inline bool query(int tl,int tr,int l,int r,int p)
		{
			if(tl<=l&&r<=tr) return vis[p];
			bool ans=1;
			if(tl<=mid) ans&=query(tl,tr,l,mid,ls(p));
			if(tr>mid) ans&=query(tl,tr,mid+1,r,rs(p));
			return ans;
		}
	}T[2];
	inline void main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>n>>m;
		for(int i=1;i<=m;++i)
		{
			int opt,x1,y1,x2,y2;
			cin>>opt;
			if(opt==1)
			{
				cin>>x1>>y1;
				T[0].update(x1,1,n,1,1);
				T[1].update(y1,1,n,1,1);
			}	
			if(opt==2)
			{
				cin>>x1>>y1;
				T[0].update(x1,1,n,1,-1);
				T[1].update(y1,1,n,1,-1);
			}
			if(opt==3)
			{
				cin>>x1>>y1>>x2>>y2;
				bool flag=T[0].query(x1,x2,1,n,1);
				flag|=T[1].query(y1,y2,1,n,1);
				if(flag) cout<<"Yes\n";
				else cout<<"No\n";
			}
		}
	}
}
signed main()
{
	red::main();
	return 0;
}