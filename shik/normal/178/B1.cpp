// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
struct DJS {
    int fa[N];
    void init( int n ) { for ( int i=1; i<=n; i++ ) fa[i]=i; }
    int Find( int x ) { return x==fa[x]?x:fa[x]=Find(fa[x]); }
    void Union( int a, int b ) { fa[Find(a)]=Find(b); }
} bcc;
int n,m;
vector<int> e[N];
void input() {
    scanf("%d%d",&n,&m);
    int a,b;
    for ( int i=0; i<m; i++ ) {
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
}
int vis[N],low[N],dfn[N];
set<PII> bri;
void go( int p, int f, int lv ) {
    vis[p]=1;
    low[p]=dfn[p]=lv;
    FOR(it,e[p]) if ( *it!=f ) {
        if ( vis[*it] ) low[p]=min(low[p],dfn[*it]);
        else {
            go(*it,p,lv+1);
            low[p]=min(low[p],low[*it]);
            if ( low[*it]>dfn[p] ) bri.insert(MP(p,*it));
        }
    }
}
vector<int> ee[N];
int fa[N][17],dep[N];
void dfs( int p, int f, int lv ) {
    fa[p][0]=f;
    dep[p]=lv;
    for ( int i=1; i<17; i++ ) fa[p][i]=fa[fa[p][i-1]][i-1];
    FOR(it,ee[p]) if ( *it!=f ) dfs(*it,p,lv+1);
}
void build() {
    bcc.init(n);
    go(1,0,1);
    for ( int i=1; i<=n; i++ ) FOR(it,e[i]) if ( !bri.count(MP(i,*it)) && !bri.count(MP(*it,i)) ) bcc.Union(i,*it);
    FOR(it,bri) {
        int a=bcc.Find(it->first);
        int b=bcc.Find(it->second);
        ee[a].push_back(b);
        ee[b].push_back(a);
    }
    dfs(bcc.Find(1),0,1);
}
inline int bit( int x, int i ) { return (x>>i)&1; }
int lca( int a, int b ) {
    if ( dep[a]<dep[b] ) swap(a,b);
    for ( int i=16; i>=0; i-- ) if ( bit(dep[a]-dep[b],i) ) a=fa[a][i];
    if ( a==b ) return a;
    for ( int i=16; i>=0; i-- ) if ( fa[a][i]!=fa[b][i] ) a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
void solve() {
    int q,a,b;
    scanf("%d",&q);
    while ( q-- ) {
        scanf("%d%d",&a,&b);
        a=bcc.Find(a); b=bcc.Find(b);
        int c=lca(a,b);
        printf("%d\n",dep[a]+dep[b]-2*dep[c]);
    }
}
int main()
{
    input();
    build();
    solve();
    return 0;
}