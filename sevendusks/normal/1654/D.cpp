/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 998244353
#define int long long
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int T,n,A[N],pr[N],w,v[N],MAX[N],cnt[N];
vector <tuple<int,int,int> > e[N]; 
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a);
		b>>=1;
		mul(a,a);
	}
	return ans;
}
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	n=200000;
	for (int i=2;i<=n;i++)
	{
		if (!v[i]) v[i]=pr[++w]=i;
		for (int j=1;j<=w;j++)
		{
			if (pr[j]>n/i||pr[j]>v[i]) break;
			v[i*pr[j]]=pr[j];
		}
	}
}
void dfs(int x,int fa)
{
	for (auto [u,a,b]:e[x]) if (u!=fa)
	{
		A[u]=A[x]*b%mod*m_pow(a,mod-2)%mod;
		int tmp=a;
		while (tmp>1)
		{
			int now=v[tmp];
			while (tmp%now==0) cnt[now]++,tmp/=now;
		}
		tmp=b;
		while (tmp>1)
		{
			int now=v[tmp];
			while (tmp%now==0) cnt[now]--,tmp/=now;
		}
		dfs(u,x);
		tmp=a;
		while (tmp>1)
		{
			int now=v[tmp];MAX[now]=max(MAX[now],cnt[now]);
			while (tmp%now==0) cnt[now]--,tmp/=now;
		}
		tmp=b;
		while (tmp>1)
		{
			int now=v[tmp];
			while (tmp%now==0) cnt[now]++,tmp/=now;
		}
	}
}
signed main()
{
	prework();
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++) e[i].clear(),MAX[i]=cnt[i]=0;
		for (int i=1;i<n;i++)
		{
			int x=read(),y=read(),a=read(),b=read(),g=__gcd(a,b);
			a/=g;b/=g;
			e[x].emplace_back(y,a,b);e[y].emplace_back(x,b,a);
		}
		A[1]=1;
		dfs(1,1);
		int ans=0;
		for (int i=1;i<=n;i++) add(ans,A[i]);
		for (int i=1;i<=n;i++) mul(ans,m_pow(i,MAX[i]));
		printf("%lld\n",ans);
	}
}