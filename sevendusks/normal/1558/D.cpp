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
const int N=4*1e5+100;
int t,n,m,x[N],y[N],fac[N],inv[N],pos[N];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
inline int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
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
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit
{
	int sh[N],ti[N];
	inline int lowbit(int x){return x&(-x);}
	inline void change(int x,int v){while(x<=n)sh[x]+=v,x+=lowbit(x);}
	inline int query(int x){int ans=0;while(x)ans+=sh[x],x-=lowbit(x);return ans;}
	inline int kth(int k)
	{
		int x=0,sum=0,lg=log(n)/log(2);
		for (int i=lg;i>=0;i--)
		{
			if (sh[x+(1<<i)]<k)
			{
				k-=sh[x+(1<<i)];
				x+=(1<<i);
			}
		}
		return x+1;
	}
}T;
void prework()
{
	n=400000;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for (int i=1;i<=n/2;i++) T.change(i,1);
}
signed main()
{
	prework();
	t=read();
	while (t--)
	{
		n=read();m=read();
		for (int i=1;i<=m;i++) x[i]=read(),y[i]=read();
		int k=0;
		for (int i=m;i>=1;i--)
		{
			pos[i]=T.kth(y[i]);
			if (T.query(pos[i]+1)>y[i]) k++;
			T.change(pos[i],-1);
		}
		printf("%lld\n",C(2*n-k-1,n));
		for (int i=1;i<=m;i++) T.change(pos[i],1);
	}
}