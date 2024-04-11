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

LL n,m,k;

LL shik( LL mid ) {
    LL ret=0;
    REP1(i,1,n) ret+=min(m,mid/i);
    return ret;
}

int main() {
    cin>>n>>m>>k;
    LL l=1,r=n*m;
    while ( l!=r ) {
        LL mid=(l+r)/2;
        if ( shik(mid)<k ) l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}