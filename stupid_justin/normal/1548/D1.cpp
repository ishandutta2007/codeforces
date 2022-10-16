#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=3e6+5;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 

void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,q,m,k,ans;
int a[16];
int t[16][3];
void DOIT()
{
    rd(n);
    t[0][0]=0;t[0][1]=0;t[0][2]=0;
    t[1][0]=0;t[1][1]=0;t[1][2]=1;
    t[2][0]=0;t[2][1]=0;t[2][2]=2;
    t[3][0]=0;t[3][1]=0;t[3][2]=3;
    t[4][0]=0;t[4][1]=1;t[4][2]=1;
    t[5][0]=0;t[5][1]=2;t[5][2]=2;
    t[6][0]=0;t[6][1]=3;t[6][2]=3;
    t[7][0]=1;t[7][1]=1;t[7][2]=1;
    t[8][0]=1;t[8][1]=1;t[8][2]=2;
    t[9][0]=1;t[9][1]=1;t[9][2]=3;
    t[10][0]=1;t[10][1]=2;t[10][2]=2;
    t[11][0]=1;t[11][1]=3;t[11][2]=3;
    t[12][0]=2;t[12][1]=2;t[12][2]=2;
    t[13][0]=2;t[13][1]=2;t[13][2]=3;
    t[14][0]=2;t[14][1]=3;t[14][2]=3;
    t[15][0]=3;t[15][1]=3;t[15][2]=3;
    for (int i=1;i<=n;i++) 
    {
        int x,y;rd(x);rd(y);
        a[x/2%2*2+y/2%2]++;
    }
    for (int i=0;i<16;i++)
    {
        if (t[i][0]==t[i][1]&&t[i][1]==t[i][2]) ans+=a[t[i][0]]*(a[t[i][0]]-1)*(a[t[i][0]]-2)/6; else
		if (t[i][0]==t[i][1]) ans+=a[t[i][0]]*(a[t[i][0]]-1)/2*a[t[i][2]]; else
		if (t[i][1]==t[i][2]) ans+=a[t[i][1]]*(a[t[i][1]]-1)/2*a[t[i][0]]; else
		ans+=a[t[i][0]]*a[t[i][1]]*a[t[i][2]];
    }
    cout<<ans<<endl;
}
signed main()
{
    //int JYZ;rd(JYZ);while (JYZ--)
    DOIT();
}
/*
*/