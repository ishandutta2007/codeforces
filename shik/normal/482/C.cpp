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

inline int two( int i ) { return 1<<i; }
inline int bit( int x, int i ) { return (x>>i)&1; }

#define N 55
#define M 20
const LL MOD=1000000000000037LL;

int n,m;
char s[N][M+1];
LL bad[1<<M];
long double dp[1<<M];
int main() {
    RI(n);
    REP(i,n) scanf("%s",s[i]);
    m=strlen(s[0]);
    REP(i,n) REP1(j,i+1,n-1) {
        int x=0;
        REP(k,m) if ( s[i][k]==s[j][k] ) x|=two(k);
        bad[x]|=1LL<<i;
        bad[x]|=1LL<<j;
    }
    for ( int i=two(m)-1; i>=0; i-- ) REP(j,m) if ( bit(i,j) ) bad[i-two(j)]|=bad[i];
    long double ans=0;
    dp[0]=1;
    REP(i,1<<m) {
        int c=__builtin_popcount(i);
        long double p=1.0L/(m-c);
        int bad_me=__builtin_popcountll(bad[i]);
        if ( bad_me==0 ) continue;
        REP(j,m) if ( !bit(i,j) ) {
            int ni=i|two(j);
            int can=bad_me-__builtin_popcountll(bad[ni]);
            double q=1.0L*can/bad_me;
            ans+=p*q*dp[i]*(c+1);
            dp[ni]+=p*(1-q)*dp[i];
        }
    }
    printf("%.14f\n",(double)ans);
    return 0;
}