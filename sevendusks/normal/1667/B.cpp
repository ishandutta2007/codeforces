/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=5*1e5+100;
int T,n,a[N],b[N],w,t[N],dp[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit//max
{
	int sh[N],n;
	inline void init(int m){n=m;memset(sh,-0x3f,(n+10)*sizeof(int));}
	int lowbit(int x){return x&(-x);}
	void change(int x,int v){while(x<=n)ckmax(sh[x],v),x+=lowbit(x);}
	int query(int x){int ans=-inf;while(x)ckmax(ans,sh[x]),x-=lowbit(x);return ans;}
}A;
struct bit1//max
{
	int sh[N],n;
	inline void init(int m){n=m;memset(sh,-0x3f,(n+10)*sizeof(int));}
	int lowbit(int x){return x&(-x);}
	void change(int x,int v){while(x)ckmax(sh[x],v),x-=lowbit(x);}
	int query(int x){int ans=-inf;while(x<=n)ckmax(ans,sh[x]),x+=lowbit(x);return ans;}
}B;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		a[0]=0;
		for (int i=1;i<=n;i++) a[i]=a[i-1]+read();
		w=0;
		for (int i=1;i<=n;i++) b[++w]=a[i];
		b[++w]=0;
		sort(b+1,b+1+w);w=unique(b+1,b+1+w)-b-1;
		for (int i=0;i<=n;i++) a[i]=lower_bound(b+1,b+1+w,a[i])-b;
		A.init(w);B.init(w);
		for (int i=1;i<=w;i++) t[i]=-inf;
		dp[0]=0;
		A.change(a[0],dp[0]);B.change(a[0],dp[0]);
		ckmax(t[a[0]],dp[0]);
		for (int i=1;i<=n;i++)
		{
			dp[i]=t[a[i]];
			ckmax(dp[i],A.query(a[i]-1)+i);
			ckmax(dp[i],B.query(a[i]+1)-i);
			A.change(a[i],dp[i]-i);
			B.change(a[i],dp[i]+i);
			ckmax(t[a[i]],dp[i]);
		}
		printf("%lld\n",dp[n]);
	}	
}