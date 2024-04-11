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

const int MOD=1e9+7;
const int inv2=500000004;

int main() {
    int a,b;
    RI(a,b);
    int ans=0;
    REP1(i,1,b-1) {
        LL l=(i+1LL*i*b%MOD)%MOD;
        LL r=(i+1LL*a*i%MOD*b%MOD)%MOD;
        LL now=(l+r)*a%MOD*inv2%MOD;
        ans=(ans+now)%MOD;
    }
    printf("%d\n",ans);
    return 0;
}