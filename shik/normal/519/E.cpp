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

inline int bit( int x, int i ) {
    return (x>>i)&1;
}

#define N 100010

VI e[N];

int fa[17][N],dep[N],sz[N];
void dfs( int p, int f, int lv ) {
    fa[0][p]=f;
    dep[p]=lv;
    sz[p]=1;
    FOR(it,e[p]) if ( *it!=f ) {
        dfs(*it,p,lv+1);
        sz[p]+=sz[*it];
    }
}

int lca( int a, int b ) {
    if ( dep[a]>dep[b] ) swap(a,b);
    REP(i,17) if ( bit(dep[b]-dep[a],i) ) b=fa[i][b];
    if ( a==b ) return a;
    for ( int i=16; i>=0; i-- ) if ( fa[i][a]!=fa[i][b] ) a=fa[i][a],b=fa[i][b];
    return fa[0][a];
}

int up( int p, int d ) {
    REP(i,17) if ( bit(d,i) ) p=fa[i][p];
    return p;
}

int main() {
    int n;
    RI(n);
    REP(i,n-1) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    dfs(1,0,1);
    REP1(i,1,16) REP1(j,1,n) fa[i][j]=fa[i-1][fa[i-1][j]];
    int m;
    RI(m);
    while ( m-- ) {
        int a,b;
        RI(a,b);
        if ( a==b ) {
            printf("%d\n",n);
            continue;
        }
        if ( dep[a]>dep[b] ) swap(a,b);
        int c=lca(a,b);
        int dac=dep[a]-dep[c];
        int dbc=dep[b]-dep[c];
        if ( dac==dbc ) {
            int pa=up(a,dac-1);
            int pb=up(b,dbc-1);
            printf("%d\n",n-sz[pa]-sz[pb]);
        } else {
            assert(dbc>dac);
            int len=dac+dbc;
            if ( len%2==0 ) {
                int mid=up(b,len/2);
                int pb=up(b,len/2-1);
                printf("%d\n",sz[mid]-sz[pb]);
            } else {
                puts("0");
            }
        }
    }
    return 0;
}