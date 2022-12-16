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
	int T,n,m,idx;
	int maxn;
	int a[N];
	int num[N],sum[N];
	int ans[N<<2],tag[N<<2];
	bool ret[N];
	typedef pair<int,int> p;
	vector<p> b[N];
	inline void build(int l,int r,int p)
	{
		ans[p]=tag[p]=0;
		if(l==r) return;
		build(l,mid,ls(p));
		build(mid+1,r,rs(p));
	}
	inline void pushdown(int l,int r,int p)
	{
		ans[ls(p)]+=tag[p];
		ans[rs(p)]+=tag[p];
		tag[ls(p)]+=tag[p];
		tag[rs(p)]+=tag[p];
		tag[p]=0;
	}
	inline void update(int tl,int tr,int l,int r,int p,int k)
	{
		if(tl<=l&&r<=tr)
		{
			ans[p]+=k;
			tag[p]+=k;
			return;
		}
		if(tag[p])pushdown(l,r,p);
		if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
		if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
		ans[p]=min(ans[ls(p)],ans[rs(p)]);
	}
	inline void main()
	{
		T=read();
		while(T--)
		{
			n=read(),m=read();
			build(1,1e5,1);
			for(int i=1;i<=n;++i)
			{
				a[i]=read();
				update(1,a[i],1,1e5,1,1);
			}
			for(int i=1;i<=m;++i)
			{
				num[i]=read();
				for(int x,j=1;j<=num[i];++j)
				{
					++idx;
					x=read();
					b[i].push_back(p(x,idx));
					sum[i]+=x; 
				}
				update(1,(sum[i]-1)/num[i]+1,1,1e5,1,-1);
			}
			for(int i=1;i<=m;++i)
			{
				update(1,(sum[i]-1)/num[i]+1,1,1e5,1,1);
				if(num[i]==1)
				{
					update(1,1e5,1,1e5,1,-1);
					ret[b[i][0].second]=(ans[1]>=0);
					update(1,1e5,1,1e5,1,1);
				}
				else
				{
					for(int j=0;j<num[i];++j)
					{
					//	cout<<(sum[i]-b[i][j].first-1)/(num[i]-1)+1<<endl;
						update(1,(sum[i]-b[i][j].first-1)/(num[i]-1)+1,1,1e5,1,-1);
						ret[b[i][j].second]=(ans[1]>=0);
						update(1,(sum[i]-b[i][j].first-1)/(num[i]-1)+1,1,1e5,1,1);
					}
				}
				
				update(1,(sum[i]-1)/num[i]+1,1,1e5,1,-1);
			}
			for(int i=1;i<=idx;++i)
			{
				if(ret[i]==0) putchar('0');
				else putchar('1');
				ret[i]=0;
			}
			puts("");
			for(int i=1;i<=m;++i)
			{
				b[i].clear();
				num[i]=sum[i]=0;
			}
			idx=maxn=0;
		}
	}
}
signed main()
{
	red::main();
	return 0;
}
/*
4
1 1
30
3
25 16 37
4 2
9 12 15 6
2
4 5
3
17 12 15

8 12
10 11
10->12

*/