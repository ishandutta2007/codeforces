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
#define M 300
#define F first
#define S second

int n;
PII p[N];
VI vx[N],vy[N];

inline bool has( int x, int y ) { return binary_search(p,p+n,MP(x,y)); }
inline bool has( const VI &v, int x ) { return binary_search(ALL(v),x); }

int main() {
    RI(n);
    REP(i,n) RI(p[i].F,p[i].S);
    sort(p,p+n);
    int ans=0;
    REP(i,n) {
        int x=p[i].F,y=p[i].S,d=x-y;
        if ( SZ(vx[x])<SZ(vy[y]) ) {
            FOR(it,vx[x]) if ( has(vy[y],*it+d) && has(*it+d,*it) ) ans++;
        } else {
            FOR(it,vy[y]) if ( has(vx[x],*it-d) && has(*it,*it-d) ) ans++;
        }
        vx[x].PB(y);
        vy[y].PB(x);
    }
    printf("%d\n",ans);
    return 0;
}