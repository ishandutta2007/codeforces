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
const int N=1e6+5;
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
int n,ans,pos;
struct A{int a,b;}p[N];
bool cmp(A x,A y){return x.b==y.b?x.a<y.a:x.b<y.b;}
int a[N],b[N],mn[N],f[N],premn[N],pref[N];
multiset<int> S;
signed main()
{
    rd(n);if (n==1) {puts("1");return 0;}for (int i=1;i<=n;i++) rd(p[i].b),rd(p[i].a);sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++) a[i]=p[i].a,b[i]=p[i].b;
    f[0]=1;pref[0]=1;
    for (int i=1;i<=n;i++) 
    {
        pos=upper_bound(b+1,b+n+1,a[i])-b-1,mn[i]=a[i]+premn[pos],premn[i]=min(premn[i-1],mn[i]-b[i]),f[i]=pref[pos];
        if (mn[i]-b[i]<premn[i-1]) pref[i]=f[i];
        else if (mn[i]-b[i]==premn[i-1]) pref[i]=(pref[i-1]+f[i])%mod;
        else pref[i]=pref[i-1];
    }
    for (int i=1;i<=n;i++) S.insert(a[i]);int MN=inf;
    for (int i=1;i<=n;i++) {S.erase(S.find(a[i]));if ((*S.rbegin())<b[i]) MN=min(MN,mn[i]);S.insert(a[i]);}
    for (int i=1;i<=n;i++) if (MN==mn[i]) {S.erase(S.find(a[i]));if ((*S.rbegin())<b[i]) ans=(ans+f[i])%mod;S.insert(a[i]);}
    cout<<ans<<endl;



}
/*
*/