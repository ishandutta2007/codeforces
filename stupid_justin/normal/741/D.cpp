#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=5e5+5;
const int M=(1<<22)+5;
const int K2=13;
const int mod=998244353;
int read(){int x=0;char ch=getchar();while(ch>'9'||ch<'0'){ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
 
int n,c[N],Map[M],ans[N],sz[N],son[N],len[N],vis[N];
int L[N],R[N],id[N],idx;
vector<int> T[N];
 
void dfs(int u)
{
    sz[u]=1,L[u]=++idx,id[idx]=u;
    for (int v:T[u])
    {
        c[v]^=c[u],len[v]=len[u]+1,dfs(v),sz[u]+=sz[v];
        if (sz[son[u]]<sz[v]) son[u]=v;
    }
    R[u]=idx;
}
 
void getans(int u,int flag)
{
    for (int v:T[u]) if (v!=son[u]) getans(v,0),ans[u]=max(ans[u],ans[v]);
    if (son[u]) getans(son[u],1),ans[u]=max(ans[u],ans[son[u]]);
    ans[u]=max(ans[u],Map[c[u]]-len[u]);
    for (int j=0;j<22;j++) ans[u]=max(ans[u],Map[c[u]^(1<<j)]-len[u]);
    Map[c[u]]=max(Map[c[u]],len[u]);
    for (int v:T[u]) if (v!=son[u])
    {
        for (int i=L[v],x;i<=R[v];i++)
        {
            x=id[i];
            if (Map[c[x]]) ans[u]=max(ans[u],Map[c[x]]+len[x]-2*len[u]);
            for (int j=0;j<22;j++) if (Map[c[x]^(1<<j)]) ans[u]=max(ans[u],Map[c[x]^(1<<j)]+len[x]-2*len[u]);
        }
        for (int i=L[v],x;i<=R[v];i++) x=id[i],Map[c[x]]=max(Map[c[x]],len[x]);
    }
    if (!flag) for (int i=L[u];i<=R[u];i++) Map[c[id[i]]]=0;
}
 
int main()
{
    rd(n);for (int i=2,x;i<=n;i++){rd(x);T[x].push_back(i);c[i]=getchar();c[i]=1<<(c[i]-'a');}
    dfs(1);getans(1,1);for (int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;
}