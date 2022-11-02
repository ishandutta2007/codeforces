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

#define N 514
int n,m,v[N],e[N][N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(v[i]);
    REP(i,m) {
        int a,b,c;
        RI(a,b,c);
        e[a][b]=e[b][a]=c;
    }
    double ans=0;
    REP1(i,1,n) REP1(j,1,n) if ( e[i][j] ) {
        double now=(double)(v[i]+v[j])/e[i][j];
        ans=max(ans,now);
    }
    printf("%.12f\n",ans);
    return 0;
}