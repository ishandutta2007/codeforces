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

inline void chkmin( map<int,int> &mp, int k, int v ) {
    if ( !mp.count(k) || v<mp[k] ) mp[k]=v;
}

#define N 314

int n,l[N],c[N];
map<int,int> dp[N];
int main() {
    RI(n);
    REP(i,n) RI(l[i]);
    REP(i,n) RI(c[i]);
    dp[0][0]=0;
    REP(i,n) FOR(it,dp[i]) {
        int k=it->first;
        int v=it->second;
        //printf("%d: (%d,%d)\n",i,k,v);
        chkmin(dp[i+1],k,v);
        chkmin(dp[i+1],__gcd(k,l[i]),v+c[i]);
    }
    if ( dp[n].count(1) ) printf("%d\n",dp[n][1]);
    else puts("-1");
    return 0;
}