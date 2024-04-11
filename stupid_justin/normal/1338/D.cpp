#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=4e6+5;
const int M=170;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,ans;
int f[N],g[N];
vector<int> T[N];
void dfs(int u,int fa)
{
    int s=T[u].size();
    for (int v:T[u]) if (v!=fa)
    {
        dfs(v,u);
        ans=max({ans,f[u]+g[v]+1,g[u]+f[v]+s-2});
        f[u]=max(f[u],g[v]);g[u]=max(g[u],f[v]);
    }
    f[u]++;g[u]+=s-1-(fa!=0);f[u]=max(f[u],g[u]);
    ans=max(ans,f[u]);
}
signed main()
{
    rd(n);for (int i=1,x,y;i<n;i++) rd(x),rd(y),T[x].push_back(y),T[y].push_back(x);
    dfs(1,0);cout<<ans<<"\n";
}
/*
*/