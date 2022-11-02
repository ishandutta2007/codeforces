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

int main() {
    LL n,m,k;
    cin>>n>>m>>k;
    if ( k>(n-1)+(m-1) ) puts("-1");
    else {
        LL ans=0;
        auto upd=[&]( int i ) {
            if ( i<0 || i>k ) return;
            LL a=n/(i+1);
            LL b=m/(k-i+1);
            ans=max(ans,a*b);
        };
        for ( int i=0; i*i<=n; i++ ) REP1(j,-5,+5) {
            upd(i+j);
            upd(n/(i+1)+j);
        }
        swap(n,m);
        for ( int i=0; i*i<=n; i++ ) REP1(j,-5,+5) {
            upd(i+j);
            upd(n/(i+1)+j);
        }
        cout<<ans<<endl;
    }
    return 0;
}