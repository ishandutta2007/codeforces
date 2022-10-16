#include<bits/stdc++.h>
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
const int mod=998244353;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(1ll*ret*x)%z;x=(1ll*x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
int V[N];
void Init(int n)
{
    for (int i=2;i<=n;i++) if (!V[i]) for (int j=i+i;j<=n;j+=i) V[j]=1;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}
int n,m,k,ans;
int a[N];

vector<int> T[N];
bool flag=0;
int gcd(int x,int y){if (y==0) return x;return gcd(y,x%y);}
int dfs(int u,int fa)
{
    if (!flag) return 0;
    int tot=T[u].size();
    for (int v:T[u]) if (v!=fa) tot-=dfs(v,u);
    if (tot%k!=0 && (tot-1)%k!=0) flag=0;
    if (!ans)
    {
        if (tot%k==0) {ans=tot;return 1;} else {ans=tot-1;return 0;}
    } else 
    {
        if (tot%k==0) {ans=gcd(ans,tot);return 1;}else {ans=gcd(ans,tot-1);return 0;}
    }
}
void chk(int x){flag=1;ans=0;k=x;dfs(1,0);if (flag) a[ans]=1;}
void DOIT()
{
    rd(n);for (int i=1;i<=n;i++) T[i].clear();
    for (int i=1;i<=n;i++) a[i]=0;
    for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
    for (int i=2;i<=n;i++) if ((n-1)%i==0) if (!V[i]) chk(i);
    a[1]=ksm(2,n-1)+mod;
    for (int i=2;i<=n;i++) a[1]-=a[i];a[1]%=mod;
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
}
signed main()
{
    Init(N-1);
    int JYZ;rd(JYZ);while (JYZ--)
    DOIT();
}
/*
*/