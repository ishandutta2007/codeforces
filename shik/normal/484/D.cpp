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

inline void chkmax( LL &a, LL b ) {
    if ( b>a ) a=b;
}

#define N 1000010

int n,a[N];
LL dp[N];
set<PII> sl,sr;

inline LL fl( int i ) { return +a[i]+dp[i-1]; }
inline LL fr( int i ) { return -a[i]+dp[i-1]; }

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) {
        dp[i]=dp[i-1];
        do {
            auto it=sl.lower_bound(MP(a[i],0));
            if ( it==sl.end() ) break;
            chkmax(dp[i],-a[i]+fl(it->second));
        } while ( 0 );
        do {
            auto it=sr.lower_bound(MP(a[i],0));
            if ( it==sr.begin() ) break;
            it--;
            chkmax(dp[i],+a[i]+fr(it->second));
        } while ( 0 );
        while ( 1 ) {
            auto it=sl.lower_bound(MP(a[i],N));
            if ( it==sl.begin() ) break;
            it--;
            if ( fl(i)>=fl(it->second) ) sl.erase(it);
            else break;
        }
        while ( 1 ) {
            auto it=sr.lower_bound(MP(a[i],0));
            if ( it==sr.end() ) break;
            if ( fr(i)>=fr(it->second) ) sr.erase(it);
            else break;
        }
        auto lit=sl.lower_bound(MP(a[i],0));
        if ( lit==sl.end() || fl(i)>fl(lit->second) ) sl.insert(MP(a[i],i));
        auto rit=sr.lower_bound(MP(a[i],N));
        if ( rit==sr.begin() || fr(i)>fr((--rit)->second) ) sr.insert(MP(a[i],i));
    }
    // REP1(i,1,n) printf("%d: %lld\n",i,dp[i]);
    cout<<dp[n]<<endl;
    return 0;
}