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

#define N 2014

double dp[N][N];
int main() {
    int n,t;
    double p;
    scanf("%d%lf%d",&n,&p,&t);
    REP1(i,0,n) dp[0][i]=i;
    REP1(i,1,t) REP1(j,0,n) dp[i][j]=p*dp[i-1][j-1]+(1-p)*dp[i-1][j];
    printf("%.9f\n",n-dp[t][n]);
    return 0;
}