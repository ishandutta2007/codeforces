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

inline int bit( int x, int i ) { return (x>>i)&1; }
inline int two( int x ) { return 1<<x; }

#define N 1000010
const int MOD=1e9+7;

inline void add( int &a, int b ) {
    a+=b;
    if ( a>=MOD ) a-=MOD;
}

inline void sub( int &a, int b ) {
    a-=b;
    if ( a<0 ) a+=MOD;
}

int n,a[N],pw2[N],dp[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    pw2[0]=0;
    REP1(i,1,n) pw2[i]=(pw2[i-1]*2+1)%MOD;
    REP(i,n) dp[a[i]]++;
    for ( int i=0; i<20; i++ ) for ( int j=0; j<N; j++ ) if ( bit(j,i) ) dp[j^two(i)]+=dp[j];
    int ans=0;
    REP(i,N) {
        int c=__builtin_popcount(i);
        if ( c%2==0 ) add(ans,pw2[dp[i]]);
        else sub(ans,pw2[dp[i]]);
    }
    printf("%d\n",ans);
    return 0;
}