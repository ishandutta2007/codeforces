#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=1e6+5;
const int M=2e7+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}


int ABS(int x){return x<0?-x:x;}
signed p[M],v[M],cnt;
void init()
{
	v[1]=1;
	for (register int i=2;i<=2e7;i++)
	{
		if (!v[i]) p[++cnt]=i,v[i]=i;
		for (register int j=1;j<=cnt;j++)
		{
			if (i*p[j]>2e7) break;
			v[i*p[j]]=p[j];
			if (i%p[j]==0) break;
		}
	}
}

signed a[M],cnta;
int P[N],C[N],tot,CC[N];
void yueshu(int x)
{
	tot=0;
	while (x!=1)
	{
		if (P[tot]!=v[x]) P[++tot]=v[x],C[tot]=1;
		else C[tot]++;
		x/=v[x];
	}
	CC[tot+1]=1;
	for (register int i=tot;i>=1;i--) CC[i]=CC[i+1]*(C[i]+1);
	for (register int k=0;k<CC[1];k++)
	{
		int tmp=1;
		for (register int i=1;i<=tot;i++) tmp*=ksm(P[i],k%CC[i]/CC[i+1]);
		a[++cnta]=tmp;
	}
}
signed MAP[M];
int abab(int x)
{
	if (MAP[x]) return MAP[x];
	int ggg=x;
	tot=0;
	while (x!=1)
	{
		if (P[tot]!=v[x]) P[++tot]=v[x];
		x/=v[x];
	}
	return MAP[ggg]=tot;
}
int c,d,x,ans,lax;
signed main()
{
	init();
	int T;cin>>T;while (T--)
	{
		ans=0;
		rd(c);rd(d);rd(x);
		//c|d+x/g
		// x 
		if (x!=lax){cnta=0;yueshu(x);}
		//lax=x;
		for (register int i=1;i<=cnta;i++)
		{
			int g=a[i];
			if ((d+x/g)%c!=0) continue;
			ans+=1LL<<abab((x+d*g)/(g*c));
		}
		cout<<ans<<endl;
	}
}