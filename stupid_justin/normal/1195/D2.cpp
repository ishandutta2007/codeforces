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
const int N=2e5+5;
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

int n,k,ans,res;
int c[N];
string s[N];
char tmp[N];
int f(string a,string b)
{
    int ret=0;
    int la=a.length(),lb=b.length(),lc=la+lb;
    while (la>=1 && lb>=1) tmp[--lc]=b[--lb],tmp[--lc]=a[--la];
    while (la>=1) tmp[--lc]=a[--la];while (lb>=1) tmp[--lc]=b[--lb];
    for (int i=0;i<a.size()+b.size();i++) ret=(ret*10+tmp[i]-'0')%mod;
    return ret;
}
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++) cin>>s[i],c[s[i].size()]++;
    for (int i=1;i<=n;i++)
    {
        string TMP="";
        for (int j=1;j<=10;j++)
        {
            TMP=TMP+"0";
            ans=(ans+c[j]*f(s[i],TMP))%mod;
            ans=(ans+c[j]*f(TMP,s[i]))%mod;
        }
    }
    cout<<ans<<endl;

}
/*

*/