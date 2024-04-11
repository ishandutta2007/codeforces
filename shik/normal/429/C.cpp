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

#define N 24
int n,c[N],cnt[N],sum[N];
bool dfs( int p ) {
    if ( c[p]==1 ) return 1;
    REP(i,p) if ( sum[i]+c[p]<c[i] && c[p]+1!=c[i] ) {
        sum[i]+=c[p];
        if ( dfs(p+1) ) return 1;
        sum[i]-=c[p];
    }
    return 0;
}
int main() {
    RI(n);
    REP(i,n) RI(c[i]);
    sort(c,c+n,greater<int>());
    if ( c[0]!=n ) return puts("NO"),0;
    if ( count(c,c+n,1)*2<=n ) return puts("NO"),0;
    if ( count(c,c+n,2) ) return puts("NO"),0;
    puts(n==1||dfs(1)?"YES":"NO");
    return 0;
}