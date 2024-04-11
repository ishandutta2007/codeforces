#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int SZ=455;
const int N=2e5+SZ+5;
const int M=1<<17;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,x[N],y[N],t[N],c[SZ+1][SZ+1];
int s[N],cb[N],ans;
void add(int x,int v){s[x]+=v,cb[x/SZ]+=v;}
signed main()
{
  
    rd(n);rd(m);
	for(int i=1;i<=n;++i) rd(x[i]),rd(y[i]);
	for(int i=1;i<=m;i++)
    {
		int o,k,v;
		rd(o);rd(k);
        if (o==1) v=1;else v=-1;
		if (o==1)t[k]=i;
		if(x[k]+y[k]<=SZ)
        {
			for(int j=t[k]+x[k];j<t[k]+x[k]+y[k];j++)
            c[x[k]+y[k]][j%(x[k]+y[k])]+=v;
		}
		else
        {
			for(int j=0;t[k]+(x[k]+y[k])*j+x[k]<=m;++j)
            {
				add(t[k]+(x[k]+y[k])*j+x[k],v);
				if(t[k]+(x[k]+y[k])*(j+1)<=m) add(t[k]+(x[k]+y[k])*(j+1),-v);
			}
		}
        ans=0;
        for (int j=0;;j+=SZ)
        {
            if (j+SZ>i){for (int k=j;k<=i;k++) ans+=s[k];break;}
		    ans+=cb[j/SZ];
        }
		for(int j=1;j<=SZ;++j)ans+=c[j][i%j];
		cout<<ans<<"\n";
	}
	return 0;
}