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
const int N=205;
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
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
void gmax(int &x,int y) {x=max(x,y);}
int n,t,d,k,sum,s;
set<int> S1,S2,T;
signed main()
{
    rd(n);
    while (n--)
    {
        rd(t);rd(d);sum+=d;
        if (d>0) {if (t) k++;else T.insert(d);if (S2.size() && d<=*S2.rbegin()) S2.insert(d);else S1.insert(d),sum+=d;}
        else {if (t) k--;else T.erase(-d);if (S2.size() && -d<=*S2.rbegin()) S2.erase(-d);else S1.erase(-d),sum+=d;}
		while (S1.size()>k) sum-=*S1.begin(), S2.insert(*S1.begin()), S1.erase(*S1.begin());
		while (S1.size()<k)sum+=*S2.rbegin(),S1.insert(*S2.rbegin()),S2.erase(*S2.rbegin());
        printf("%lld\n",sum+min(S1.size()?(T.size()?*T.rbegin():0)-*S1.begin():0LL,0LL));
    }
}
/*
 k 
 k-1  k  k+1 
 k  k-1  k+1 
 k 
 set 

*/