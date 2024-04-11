
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
const int N=500+5;
const int M=1<<17;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f;
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
int n,m,ans;
int a[N][N],s[N][N],k[N];
char c[N];
int S(int a,int b,int c,int d)
{
    return s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
}
void DOIT()
{
    rd(n);rd(m);ans=n*m;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",c+1);
        for (int j=1;j<=m;j++) a[i][j]=c[j]-'0';
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
    for (int l=1;l<=m;l++) for (int r=l+3;r<=m;r++) 
    {
        for (int i=n-3;i>=1;i--)
        if (i==n-3)
        {
            k[i]=r-l-1-S(n,l+1,n,r-1);
            k[i]+=S(i,l+1,n-1,r-1);
            k[i]+=n-i-S(i,l,n-1,l);
            k[i]+=n-i-S(i,r,n-1,r);
        } else 
        {
            k[i]=r-l-1-S(i+3,l+1,i+3,r-1);
            k[i]+=S(i,l+1,i+2,r-1);
            k[i]+=3-S(i,l,i+2,l);
            k[i]+=3-S(i,r,i+2,r);
            k[i]=min(k[i],k[i+1]+(!a[i][l])+(!a[i][r])+S(i,l+1,i,r-1));
        }
        for (int i=1;i<=n-4;i++)
        ans=min(ans,k[i+1]+r-l-1-S(i,l+1,i,r-1));
    }
    cout<<ans<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();

}
/*

*/