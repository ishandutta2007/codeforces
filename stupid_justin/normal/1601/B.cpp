
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


int n,m,k;
int a[N],b[N];
struct pos{int i,a,b;}p[N];
bool cmp(pos x,pos y){return x.i-x.a<y.i-y.a;}
bool cmp2(pos x,pos y){return x.i<y.i;}
vector<int> pre[N];
int f[N],t[N];//
vector<int> ans;
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(p[i].a);
    for (int i=1;i<=n;i++) rd(p[i].b),p[i].i=i;
    for (int i=1;i<=n;i++) pre[p[i].i+p[i].b].push_back(i);
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++) f[i]=n+1;
    bool flag=1;int j=1;
    int la=0;
    while (flag)
    {
        flag=0;
        int nla=0;
        while (j<=n && p[j].i-p[j].a<=la)
        {
            f[p[j].i]=la;flag=1;
            for (int x:pre[p[j].i]) nla=max(nla,x);
            j++;
        }
        la=nla;
    }
    sort(p+1,p+n+1,cmp2);
    if (f[n]==n+1) {puts("-1");} else 
    {
        int x=n;
        for (int x=f[n];x;x=f[x]) ans.push_back(x),x+=p[x].b;
        ans.push_back(0);
        cout<<ans.size()<<"\n";
        for (int x:ans) cout<<x<<" ";cout<<"\n";
    }
}
/*
*/