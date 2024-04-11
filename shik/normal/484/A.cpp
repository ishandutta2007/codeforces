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

#define bc __builtin_popcountll
int main() {
    int t;
    RI(t);
    while ( t-- ) {
        LL l,r;
        cin>>l>>r;
        LL ans=l;
        REP(i,60) {
            l|=1LL<<i;
            if ( l<=r && bc(l)>bc(ans) ) ans=l;
        }
        cout<<ans<<endl;
    }
    return 0;
}