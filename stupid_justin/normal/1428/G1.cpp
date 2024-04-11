
#include<bits/stdc++.h>
#define int long long
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
const int N=2e6+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;
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
int F[7],p[7];
int n,k,q;
int S[N][6],v[N][6];
int f(int n,int x)
{
    if (n>k*(p[x+1]-1)) return -inf;
    if (x==0) return ((n/9==k-1 && n%3!=0)?n/9*3:n/3)*F[0];
    if (v[n][x]) return S[n][x];
    int ret=0,l=max(0LL,(n-k*(p[x]-1)+p[x]-1)/p[x]),r=min(9*k,n/p[x]);
    for (int i=l;i<=r;i++) ret=max(ret,f(n-i*p[x],x-1)+((i/9==k-1 && i%3!=0)?i/9*3:i/3)*F[x]);
    v[n][x]=1;S[n][x]=ret;
    return ret;
}
signed main()
{
    rd(k);for (int i=0;i<=5;i++) rd(F[i]);
    p[0]=1;for (int i=1;i<=6;i++) p[i]=p[i-1]*10;
    rd(q);while (q--) rd(n),cout<<f(n,5)<<"\n";
}