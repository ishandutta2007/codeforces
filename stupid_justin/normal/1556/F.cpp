#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N=15;
const int M=2e6+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[M],fac[M],ifc[M]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=1ll*ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return 1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}

int n,ans;
int a[N],g[N][N];
int f[1<<14];
vector<int> v1,v2;
signed main()
{
    Init(M-1);
	rd(n);for (int i=0;i<n;i++) rd(a[i]);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) g[i][j]=a[i]*inv[a[i]+a[j]]%mod;
    for (int S=1;S<(1<<n);S++)
    {
        f[S]=1;for (int T=(S-1)&S;T;T=(T-1)&S)
        {
            int X=S-T;
            v1.clear();v2.clear();
            for (int i=0;i<n;i++)
            {
                if (T>>i&1) v1.push_back(i);
                if (X>>i&1) v2.push_back(i);
            }
            int P=1;
            for (int i:v1) for (int j:v2) P=P*g[i][j]%mod;
            f[S]=(f[S]-P*f[T]%mod+mod)%mod;
        }
    }
    for (int S=1;S<(1<<n);S++)
    {
        v1.clear();v2.clear();
        for (int i=0;i<n;i++) if (S>>i&1) v1.push_back(i);else v2.push_back(i);
        int P=1;
        for (int i:v1) for (int j:v2) P=P*g[i][j]%mod;
        ans=(ans+P*f[S]%mod*v1.size())%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}
/*

*/