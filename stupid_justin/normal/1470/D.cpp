
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

vector<int> G[N];
int vis[N],c[N];
int p[N],cnt;

int n,m,k;
vector<int> ans;
void dfs(int u){vis[u]=1;p[++cnt]=u;for (int v:G[u]) if (!vis[v]) dfs(v);}
void DOIT()
{
    rd(n);rd(m);for (int i=1;i<=n;i++) vis[i]=c[i]=0,G[i].clear();ans.clear();
    for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[x].push_back(y),G[y].push_back(x);
    cnt=0;dfs(1);if (cnt!=n) {puts("NO");return;}
    for (int j=1;j<=n;j++) {int i=p[j];bool f=1;for (int v:G[i]) if (c[v]) f=0;if (f) c[i]=1,ans.push_back(i);}
    puts("YES");cout<<ans.size()<<"\n";for (int x:ans) cout<<x<<" ";cout<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/