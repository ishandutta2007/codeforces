#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long 
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
#define eps (1e-8)
	inline int read()
	{
		int x=0;char ch,f=0;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=1,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	const int N=3e5+10,mod=998244353;
	int T,n,x;
	int a[N],s[N];
	int ans[N<<2];
	inline void build(int l,int r,int p)
	{
		if(l==r){ans[p]=s[l];return;}
		build(l,mid,ls(p));
		build(mid+1,r,rs(p));
		ans[p]=max(ans[ls(p)],ans[rs(p)]);
	}
	inline int query(int tl,int tr,int l,int r,int p)
	{
		if(tl>tr) return -1e18-7;
		if(tl<=l&&r<=tr) return ans[p];
		int sum=-1e18-7;
		if(tl<=mid) sum=max(sum,query(tl,tr,l,mid,ls(p)));
		if(tr>mid) sum=max(sum,query(tl,tr,mid+1,r,rs(p)));
		return sum;
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read();
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
			}
			x=read();
			for(int i=1;i<=n;++i)
			{
				a[i]-=x;
				s[i]=s[i-1]+a[i];
			}
			build(1,n,1);
			int tot=n,pre=1;
			for(int minn,i=2;i<=n;++i)
			{
				minn=query(pre,i-2,1,n,1);
				if(pre==1) minn=max(minn,0ll);
			//	cout<<i<<' '<<pre<<' '<<minn<<' '<<s[i]<<"!!"<<endl;
				if(s[i]-minn<0)
				{
					--tot;
					pre=i;
				}
			}
			printf("%lld\n",tot);
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
5
1 8 3 7 7
5

*/