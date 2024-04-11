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
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
const int N=4e5+5;
const int M=3e11+5;
const int SZ=550;
const double eps=1e-9;
const int inf=1e11+5;
const int mod=998244853;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m,x,sum,l,r;
int a[N],ans[N],vis[N];
vector<pii> G[N];
void dfs(int u){vis[u]=1;for (pii p:G[u]) if (!vis[p.fi]) {dfs(p.fi);if (a[p.fi]>=0) a[u]+=a[p.fi],ans[++l]=p.se;else ans[--r]=p.se;}}
signed main()
{
    rd(n);rd(m);rd(x);for (int i=1;i<=n;i++) rd(a[i]),sum+=a[i],a[i]-=x;
	if (sum<(n-1)*x) {puts("NO");return 0;}
	for (int i=1,x,y;i<=m;i++) rd(x),rd(y),G[x].push_back(mp(y,i)),G[y].push_back(mp(x,i));
	puts("YES");l=0;r=n;dfs(1);
	for (int i=1;i<=n-1;i++) cout<<ans[i]<<"\n";
}
/*
*/