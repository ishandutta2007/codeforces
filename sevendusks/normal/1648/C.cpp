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
const int N=2*1e5+100;
int n,m,lim,s[N],t[N],fac[N],inv[N],c[N];
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
	n=200010;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
struct bit//
{
	int n,sh[N];
	inline void init(int m){n=m;memset(sh,0,(n+10)*sizeof(int));}
	int lowbit(int x){return x&(-x);}
	void change(int x,int v){while(x<=n)add(sh[x],v),x+=lowbit(x);}
	int query(int x){int ans=0;while(x)add(ans,sh[x]),x-=lowbit(x);return ans;}
}T;
signed main()
{
	prework();
	n=read();m=read();
	for (int i=1;i<=n;i++) s[i]=read();
	for (int i=1;i<=m;i++) t[i]=read();
	for (int i=1;i<=n;i++) c[s[i]]++;
	lim=max(*max_element(s+1,s+1+n),*max_element(t+1,t+1+m));
	int k=1,up=min(n,m),ans=0;T.init(lim);
	for (int i=1;i<=lim;i++) mul(k,inv[c[i]]),T.change(i,c[i]);
	bool bl=1;
	for (int i=1;i<=up;i++)
	{
		add(ans,k*fac[n-i]%mod*T.query(t[i]-1)%mod);
		if (c[t[i]])
		{
			mul(k,c[t[i]]);
			c[t[i]]--;
			T.change(t[i],-1);
		}
		else{bl=0;break;}
	}
	if (n<m&&bl) add(ans,1);
	printf("%lld\n",ans);
}