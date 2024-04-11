// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 100010
const int MOD=1e9+7;

inline void fix( LL &x ) {
    x%=MOD;
    if ( x<0 ) x+=MOD;
}

int n;
vector<PII> e[N];
void input() {
    RI(n);
    REP(i,n-1) {
        int a,b,c;
        RI(a,b,c);
        e[a].PB(MP(b,c));
        e[b].PB(MP(a,c));
    }
}

int fa[17][N],dep[N],sz[N];
LL d1[N];
void dfs( int p, int f, int lv, LL d ) {
    fa[0][p]=f;
    dep[p]=lv;
    sz[p]=1;
    d1[p]=d%MOD;
    FOR(it,e[p]) if ( it->first!=f ) {
        dfs(it->first,p,lv+1,d+it->second);
        sz[p]+=sz[it->first];
    }
}

LL dp1[N][2];
void get_dp1( int p, int f ) {
    LL x1=0,x2=0;
    FOR(it,e[p]) {
        int q=it->first;
        if ( q==f ) continue;
        get_dp1(q,p);
        LL d=it->second;
        LL y1=dp1[q][0];
        LL y2=dp1[q][1];
        x1+=y1+d*sz[q];
        x2+=y2+2*d*y1+sz[q]*d%MOD*d;
        fix(x1);
        fix(x2);
    }
    dp1[p][0]=x1;
    dp1[p][1]=x2;
}

LL dp2[N][2];
void get_dp2( int p, int f ) {
    LL x1=dp1[p][0]+dp2[p][0];
    LL x2=dp1[p][1]+dp2[p][1];
    FOR(it,e[p]) {
        int q=it->first;
        if ( q==f ) continue;
        LL d=it->second;
        LL y1=dp1[q][0];
        LL y2=dp1[q][1];
        LL z1=x1-(y1+d*sz[q]);
        LL z2=x2-(y2+2*d*y1+sz[q]*d%MOD*d);
        fix(z1);
        fix(z2);
        dp2[q][0]=z1+d*(n-sz[q]);
        dp2[q][1]=z2+2*d*z1+(n-sz[q])*d%MOD*d;
        fix(dp2[q][0]);
        fix(dp2[q][1]);
        get_dp2(q,p);
    }
}

void build() {
    dfs(1,0,1,0);
    REP(i,16) REP1(j,1,n) fa[i+1][j]=fa[i][fa[i][j]];
    get_dp1(1,0);
    get_dp2(1,0);
}

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

int lca( int a, int b ) {
    if ( dep[a]>dep[b] ) swap(a,b);
    REP(i,17) if ( bit(dep[b]-dep[a],i) ) b=fa[i][b];
    if ( a==b ) return a;
    for ( int i=16; i>=0; i-- ) if ( fa[i][a]!=fa[i][b] ) a=fa[i][a],b=fa[i][b];
    return fa[0][a];
}

void solve_1( int a, int b ) {
    LL d=d1[a]-d1[b];
    fix(d);
    LL tot=dp1[a][1]+dp2[a][1];
    fix(tot);
    LL y1=dp2[b][0];
    LL y2=dp2[b][1];
    LL now=y2+2*d*y1+(n-sz[b])*d%MOD*d;
    fix(now);
    LL ans=tot-2*now;
    fix(ans);
    //printf("d=%lld, tot=%lld, y1=%lld, y2=%lld, now=%lld, ans=%lld\n",d,tot,y1,y2,now,ans);
    printf("%d\n",(int)ans);
}

void solve_2( int a, int b, int c ) {
    LL d=d1[a]+d1[b]-2*d1[c];
    fix(d);
    LL tot=dp1[a][1]+dp2[a][1];
    fix(tot);
    LL y1=dp1[b][0];
    LL y2=dp1[b][1];
    LL now=y2+2*d*y1+sz[b]*d%MOD*d;
    fix(now);
    LL ans=2*now-tot;
    fix(ans);
    printf("%d\n",(int)ans);
}

void solve() {
    int q,a,b;
    RI(q);
    while ( q-- ) {
        RI(a,b);
        int c=lca(a,b);
        if ( c==b ) solve_1(a,b);
        else solve_2(a,b,c);
    }
}

int main() {
    input();
    build();
    solve();
    return 0;
}