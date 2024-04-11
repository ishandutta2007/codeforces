#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const ld PI=acos(-1);
const int N=1e6+5;
int n,m,q;
vector<int>g[N];
int f[N];
int fa(int x){return f[x]==x?x:f[x]=fa(f[x]);}
bool in[N];
vector<int>ans[N],tmp;
int dep[N],u[N];
void dfs(int x,int fax){
    dep[x]=dep[fax]+1;
    u[x]=fax;
    for(int v:g[x])if(v!=fax)
        dfs(v,x);
}
int al=0;
void sol(int x,int fax){
    int now=0;
    for(int v:g[x])if(v!=fax){
        sol(v,x);
        now^=in[v];
    }
    now^=in[x];
    if(now==1)++al;
}
int main(){
    scanf("%d%d",&n,&m);
    rep(i,n)f[i]=i;
    rep(i,m){
        int x,y;
        scanf("%d%d",&x,&y);
        int u=fa(x),v=fa(y);
        if(u==v)continue;
        f[u]=v;
        g[x].pb(y);g[y].pb(x);
    }
    dfs(1,0);
    scanf("%d",&q);
    rep(i,q){
        int x,y;
        scanf("%d%d",&x,&y);
        int xx=x,yy=y;
        if(dep[x]<dep[y])swap(x,y);
        while(dep[x]>dep[y])in[x]^=1,x=u[x];
        while(x!=y)in[x]^=1,x=u[x],in[y]^=1,y=u[y];
        int lca=x;
        tmp.clear();
        x=xx;
        while(x!=lca)tmp.pb(x),x=u[x];
        for(int v:tmp)ans[i].pb(v);
        ans[i].pb(lca);
        tmp.clear();
        y=yy;
        while(y!=lca)tmp.pb(y),y=u[y];
        reverse(all(tmp));
        for(int v:tmp)ans[i].pb(v);
    }
    rep(i,n)if(in[i]){
        puts("NO");
        sol(1,0);
        printf("%d\n",al/2);
        return 0;
    }
    puts("YES");
    rep(i,q){
        int mx=ans[i].size();
        printf("%d\n",mx);
        rep(j,mx)printf("%d%c",ans[i][j-1]," \n"[j==mx]);
    }
    return 0;
}
/*
a<=b
c<=d
ac+db-(ad+bc)
=a(c-d)+b(d-c)
=(d-c)(b-a)>=0


*/