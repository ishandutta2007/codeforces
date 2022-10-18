/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 998244353
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int t,n,f[N],p[N],v[N],w,mu[N];
int g[N];
vector <int> e[N],ok;
bool bl;
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
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
void dfs(int x,int fa)
{
	bool bl=1;
	for (int u:e[x]) if (u!=fa)
	{
		dfs(u,x);
		if (len(e[u])!=1) bl=0;
	}
	if (bl) ok.push_back(x);
}
int d,dg[N],to[N];
void dfs1(int x,int fa)
{
	if (!bl) return;
	dg[x]=0;to[x]=0;
	for (int u:e[x]) if (u!=fa)
	{
		dfs1(u,x);
		if (!to[u]) dg[x]++;
		if (!bl) break;
	}
	if (dg[x]%d==0) return;
	if (x==1){bl=0;return;}
	if ((dg[x]+1)%d==0){to[x]=1;return;}
	bl=0;
}
void check(int i)
{
	if (i>n) return;
	d=i;bl=1;
	dfs1(1,1);
	if (bl) add(f[i],1),del(f[1],1);
}
void prework()
{
	n=100000;
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!v[i]) v[i]=p[++w]=i,mu[i]=mod-1;
		for (int j=1;j<=w;j++)
		{
			if (p[j]>n/i||p[j]>v[i]) break;
			v[i*p[j]]=p[j];
			if (i%p[j]) mu[i*p[j]]=mod-mu[i];
			else mu[i*p[j]]=0;
		}
	}
}
signed main()
{
	prework();
	t=read();
	while (t--)
	{
		n=read();
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].push_back(v);e[v].push_back(u);
		}
		ok.clear();
		dfs(1,1);
		int x=0;
		for (int i:ok)
		{
			if (i==1) x=gcd(x,len(e[i]));
			else x=gcd(x,lcm(len(e[i]),len(e[i])-1));
		}
		memset(f,0,(n+10)*sizeof(int));
		memset(g,0,(n+10)*sizeof(int));
		f[1]=m_pow(2,n-1);
		check(x);
		for (int i=2;i*i<=x;i++) if (x%i==0)
		{
			check(i);
			if (i*i!=x) check(x/i);
		}
		for (int i=n;i>=2;i--) if (2*i<=n)
		{
			int sum=0;
			for (int j=2*i;j<=n;j+=i) add(sum,f[j]);
			del(f[i],sum);
		}
		int all=0;
		for (int i=2;i<=n;i++) add(all,f[i]);
		f[1]=(m_pow(2,n-1)-all+mod)%mod;
		for (int i=1;i<=n;i++) printf("%lld ",f[i]);
		printf("\n");
	}
}