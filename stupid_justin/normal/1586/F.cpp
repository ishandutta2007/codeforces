
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=2000+5;
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
int n,k,c,t;
int g[N][N];
void solve(int x,int l,int r)
{
    if (x==1)
    {
        for (int i=l;i<=r;i++) for (int j=l;j<=r;j++) g[i][j]=x;
    } else 
    {
        int len=r-l+1;len+=k-1;len/=k;
        for (int i=l;i<=r;i+=len)
        {
            solve(x-1,i,min(i+len-1,r));
        }
        for (int i=l;i<=r;i+=len) for (int j=i+len;j<=r;j+=len) if (i!=j)
        {
            for (int o=i;o<=min(i+len-1,r);o++)
            for (int p=j;p<=min(j+len-1,r);p++)
            g[o][p]=x;
        }
        
    }
}
void DOIT()
{
    rd(n);rd(k);
    c=0;t=1;while (t<n) c++,t*=k;
    solve(c,1,n);
    cout<<c<<"\n";
    for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) cout<<g[i][j]<<" ";cout<<endl;
}
signed main()
{
    DOIT();
}
/*
*/