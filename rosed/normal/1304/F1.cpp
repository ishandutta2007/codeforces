#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid ((l+r)>>1)
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();} 
		return f?x:-x;
	}
	const int N=2e4+10;
	int n,m,k,ret;
	int a[51][20010];
	int s[51][20010];
	int f[20010];
	int ans[N<<2],tag[N<<2];
	inline void pushdown(int p)
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
		if(tag[p]) pushdown(p);
		if(tl<=mid) update(tl,tr,l,mid,ls(p),k);
		if(tr>mid) update(tl,tr,mid+1,r,rs(p),k);
		ans[p]=max(ans[ls(p)],ans[rs(p)]);
	}
	inline void main()
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				a[i][j]=read();
				s[i][j]=s[i][j-1]+a[i][j];
			}
		}
		if(k>=m)
		{
			for(int i=1;i<=n;++i) ret+=s[i][m];
			printf("%lld\n",ret);
			return;
		}
		for(int i=1;i<=m-k+1;++i)
		{
			f[i]=(s[1][i+k-1]-s[1][i-1])+(s[2][i+k-1]-s[2][i-1]);
		}
		for(int i=2;i<=n;++i)
		{
			memset(ans,0,sizeof(ans));
			memset(tag,0,sizeof(tag));
			for(int j=1;j<=m;++j) update(j,j,1,m,1,f[j]);
			for(int j=1;j<k;++j)
			{
				update(1,j,1,m,1,-a[i][j]);
			}
			for(int j=1;j<=m-k+1;++j)
			{
				update(j,j+k-1,1,m,1,-a[i][j+k-1]);
				f[j]=ans[1]+(s[i][j+k-1]-s[i][j-1])+(s[i+1][j+k-1]-s[i+1][j-1]);
				update(max(1ll,j-k+1),j,1,m,1,a[i][j]);
			}
		}
		for(int i=1;i<=m;++i) ret=max(ret,f[i]);
		printf("%lld\n",ret);
	}
}
signed main()
{
//	freopen("data.out","r",stdin);
//	freopen("ans.out","w",stdout);
	red::main();
	return 0;
}
/*
5
1 2
2 3
3 4
4 5
5
1 4 1 3 2

*/