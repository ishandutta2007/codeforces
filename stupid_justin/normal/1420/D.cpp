
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
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
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
int n,q,m,k,ans;
struct seg{int l,r;bool operator<(const seg &o)const{return r==o.r?l<o.l:r<o.r;}}s[N];
bool cmp(seg a,seg b){return a.l<b.l;}
multiset<seg> S;
signed main()
{
    Init(N-1);
    rd(n);rd(k);for (int i=1;i<=n;i++) rd(s[i].l),rd(s[i].r);sort(s+1,s+n+1,cmp);
    for (int i=1;i<=n;)
    {
        int j=i;while (s[j].l==s[i].l) j++;
        while (!S.empty()){seg x=*S.begin();if (x.r<s[i].l) S.erase(S.begin());else break;}
        int a=j-i,b=S.size();// a  1 a b  k  ab  k  b  k 
        ans=(ans+C(a+b,k)-C(b,k))%mod;
        for (int t=i;t<j;t++) S.insert(s[t]);i=j;
    }
    cout<<(ans+mod)%mod<<endl;

}