#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}
int prim[maxn],vis[maxn],cnt,fac[maxn],inv[maxn];
int n,A,B,s,t,ans;
int a[N];
vector<int> vec[N];
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=n;i>=1;i--) vec[a[i]].push_back(i);
    for (int i=1;i<=n;i++)
    {
		A=B=0;
        if (!vec[s].size()) A=n+1;
		if (!A) A=vec[s].back();
		if (!vec[t].size()) B=n+1;
		if (!B) B=vec[t].back();
        if (s==a[i]) A=n+5;if (t==a[i]) B=n+5;
        if (A<=B && s!=a[i]) ans++;
        if (A>B && t!=a[i]) ans++;
        if (A<=B) s=a[i];else t=a[i];
        vec[a[i]].pop_back();
    }
    cout<<ans<<endl;
}