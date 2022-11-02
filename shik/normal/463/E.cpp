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
#define M 2000010
int n,q,a[N];
vector<int> fac[M],e[N];
vector<PII> app[M];

int sol[N];
void go( int p, int f, int lv ) {
    PII mx=MP(-1,-1);
    FOR(it,fac[a[p]]) {
        if ( !app[*it].empty() ) mx=max(mx,app[*it].back());
        app[*it].PB(MP(lv,p));
    }
    sol[p]=mx.second;
    FOR(it,e[p]) if ( *it!=f ) go(*it,p,lv+1);
    FOR(it,fac[a[p]]) app[*it].pop_back();
}

int main() {
    REP1(i,2,M-1) if ( fac[i].empty() )
        for ( int j=i; j<M; j+=i ) fac[j].PB(i);
    RI(n,q);
    REP1(i,1,n) RI(a[i]);
    REP(i,n-1) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    go(1,0,1);
    while ( q-- ) {
        int op;
        RI(op);
        if ( op==1 ) {
            int v;
            RI(v);
            printf("%d\n",sol[v]);
        } else if ( op==2 ) {
            int v,w;
            RI(v,w);
            a[v]=w;
            go(1,0,1);
        }
    }
    return 0;
}