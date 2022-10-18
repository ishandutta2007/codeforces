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
int T,n,m,k,q,vr[N],vc[N],x[N],y[N],ans;
int tr[N],tc[N],dfn;
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
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();k=read();q=read();
		for (int i=1;i<=q;i++) x[i]=read(),y[i]=read();
		dfn++;
		int r=0,c=0;ans=1;
		for (int i=q;i>=1;i--)
		{
			if (r==n||c==m) break;
			if (vr[x[i]]!=dfn||vc[y[i]]!=dfn) mul(ans,k);
			if (vr[x[i]]!=dfn) r++;
			if (vc[y[i]]!=dfn) c++;
			vr[x[i]]=vc[y[i]]=dfn;
		}
		printf("%lld\n",ans);
	}
}