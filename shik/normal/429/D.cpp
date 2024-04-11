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

LL sq( LL x ) { return x*x; }

struct P { LL x,y; } p[N];
LL dis( const P &a, const P &b ) { return sq(a.x-b.x)+sq(a.y-b.y); }
inline bool operator <( const P &a, const P &b ) { return a.y<b.y; }

LL ans;
void go( int l, int r ) {
    if ( l+1==r ) return;
    int m=(l+r)/2;
    go(l,m);
    go(m,r);
    sort(p+l,p+r);
    for ( int i=l; i<r; i++ ) for ( int j=i+1; j<r && j<i+20; j++ ) ans=min(ans,dis(p[i],p[j]));
}

int n,a[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    REP(i,n-1) a[i+1]+=a[i];
    REP(i,n) p[i]=P{i,a[i]};
    ans=dis(p[0],p[1]);
    go(0,n);
    cout<<ans<<endl;
    return 0;
}