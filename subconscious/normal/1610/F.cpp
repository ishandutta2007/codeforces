#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= n; ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckcjb
#define x1 fuckjsb
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;
typedef vector<int> vi;
const int N = 6e5+5,M=N*2, mod = 1e9 + 7;
int T,n,m;
int u[N],v[N],w[N],sum[2][N];
int ans[N];
namespace UndirectedGraph{
    int n,m,i,x,y,d[N],g[N],v[M<<1],w[M<<1],vis[M<<1],nxt[M<<1],ed;
    int ans[M],cnt;
    void add(int x,int y,int z){
        d[x]++;
        v[++ed]=y;w[ed]=z;nxt[ed]=g[x];g[x]=ed;
    }
    void dfs(int x){
        for(int&i=g[x];i;){
            if(vis[i]){i=nxt[i];continue;}
            vis[i]=vis[i^1]=1;
            int j=w[i];
            dfs(v[i]);
            ans[++cnt]=j;
        }
    }
    void solve(){
        //for(i=1;i<=m;i++)scanf("%d%d",&x,&y),add(x,y,i),add(y,x,-i);
        for(i=1;i<=n;i++)if(g[i]){dfs(i);}
    }
}
int c[N];
int main()
{
    scanf("%d%d",&n,&m);
    UndirectedGraph::n=2*n+1; int s=0;
    rep(i,m)scanf("%d%d%d",u+i,v+i,w+i),++sum[w[i]-1][u[i]],++sum[w[i]-1][v[i]];
    rep(i,n)if(sum[0][i]%2==1)++s;
    UndirectedGraph::ed=1;
    rep(i,m)
        if(w[i]==1)UndirectedGraph::add(u[i],v[i],i),UndirectedGraph::add(v[i],u[i],-i);
        else UndirectedGraph::add(u[i]+n,v[i]+n,i),UndirectedGraph::add(v[i]+n,u[i]+n,-i);
    int cnt=m;
    rep(i,n)if(sum[0][i]%2==1&&sum[1][i]%2==1){
        ++cnt;
        UndirectedGraph::add(i,i+n,cnt),UndirectedGraph::add(i+n,i,-cnt);
    }else if(sum[0][i]%2==1){
        ++cnt;
        UndirectedGraph::add(i,2*n+1,cnt),UndirectedGraph::add(2*n+1,i,-cnt);
    }else if(sum[1][i]%2==1){
        ++cnt;
        UndirectedGraph::add(i+n,2*n+1,cnt),UndirectedGraph::add(2*n+1,i+n,-cnt);
    }
    UndirectedGraph::m=cnt;
    UndirectedGraph::solve();
    rep(i,cnt){
        int x=UndirectedGraph::ans[i];
        // printf("%d\n",x);
        if(abs(x)<=m){
            if(x<0)ans[abs(x)]=2;
            else ans[abs(x)]=1;
        }
    }
    
    // rep(i,m)if(ans[i]==1)c[u[i]]-=w[i],c[v[i]]+=w[i];
    // else c[u[i]]+=w[i],c[v[i]]-=w[i];
    // rep(i,n)printf("%d%c",c[i]," \n"[i==n]);

    printf("%d\n",s);
    rep(i,m)printf("%d",ans[i]);
    puts("");
    return 0;
}
/*
(a,b)=1
a^2+b^2:ab=p:q

p/q=a/b+b/a
*/