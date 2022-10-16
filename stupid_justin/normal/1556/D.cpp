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
const int N=2e6+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=1ll*ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return 1ll*fac[n]*ifc[m]%mod*ifc[n-m]%mod;}

int n,k,x,y,s;
int a[N],b[N];
int ask(int x,int y)
{
    int s=0,t;
    cout<<"or "<<x<<" "<<y<<endl;cin>>t;s+=t;
    cout<<"and "<<x<<" "<<y<<endl;cin>>t;s+=t;
    return s;
}
signed main()
{
	rd(n);rd(k);
    for (int i=2;i<=n;i++) a[i]=ask(1,i);
    a[1]=ask(2,3);
    b[1]=(a[2]+a[3]-a[1])/2;
    for (int i=2;i<=n;i++) b[i]=a[i]-b[1];
    sort(b+1,b+n+1);
    cout<<"finish "<<b[k]<<endl;

}
/*
*/