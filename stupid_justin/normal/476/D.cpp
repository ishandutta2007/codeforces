#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#define int long long 
#define ri int
#define rd(x) x=read()
using namespace std;
const int N=10000+5;
const int M=1005;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
int pw[N];
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
	pw[0]=1;for (int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
}
int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int n,k,Max;
int a[N][4];
//1 2 3 5
//4 7 9 11
//8 13 15 17  
//
/*
*/

void solve()
{
    for (int i=1;i<=n;i++) a[i][0]=i*6-5,a[i][1]=i*6-4,a[i][2]=i*6-3,a[i][3]=i*6-1;
    Max=n*6-1;
}
signed main()
{
	rd(n);rd(k);
	solve();
	for (int i=1;i<=n;i++) for (int j=0;j<=3;j++) a[i][j]*=k;
	cout<<Max*k<<endl;
	for (int i=1;i<=n;i++) cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<"\n";
	
}