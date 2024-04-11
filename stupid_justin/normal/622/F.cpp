#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
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
const int M=6e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,pre=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')pre=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*pre;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)wt(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,k,ans,y;
int fac[N],pl[N],pr[N];
void init(){pl[0]=pr[k+3]=fac[0]=1;for (int i=1;i<=k+2;i++) pl[i]=pl[i-1]*(n-i)%mod,fac[i]=fac[i-1]*i%mod;for (int i=k+2;i>=1;i--) pr[i]=pr[i+1]*(n-i)%mod;}
signed main()
{
    rd(n);rd(k);init();
    for (int i=1;i<=k+2;i++)
    {
        y=(y+ksm(i,k))%mod;
        int a=pl[i-1]*pr[i+1]%mod;
        int b=fac[i-1]*((k-i)&1?-1:1)*fac[k+2-i]%mod;
        ans=(ans+y*a%mod*ksm(b)%mod)%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}
/*

*/