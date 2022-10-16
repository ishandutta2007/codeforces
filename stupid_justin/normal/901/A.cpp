
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
int n,m,k,ans;
int a[N],b[N];
vector<int> ans1,ans2;
vector<int> T[N];
signed main()
{
    bool flag=0;
    rd(n);for (int i=0;i<=n;i++) rd(a[i]);
    for (int i=0;i<n;i++) if (a[i]>1 && a[i+1]>1) flag=1;
    if (flag==0) {puts("perfect");return 0;}
    puts("ambiguous");
    ans1.push_back(0);ans2.push_back(0);T[0].push_back(1);k=1;
    for (int i=1;i<=n;i++)
    {
        k++;T[i].push_back(k);
        ans1.push_back(T[i-1][0]);
        ans2.push_back(T[i-1][0]);
        for (int j=2;j<=a[i];j++)
        {
            k++;T[i].push_back(k);
            ans1.push_back(T[i-1][0]);
            ans2.push_back(T[i-1].back());
        }
    }
    for (int x:ans1) cout<<x<<" ";cout<<"\n";
    for (int x:ans2) cout<<x<<" ";cout<<"\n";


}