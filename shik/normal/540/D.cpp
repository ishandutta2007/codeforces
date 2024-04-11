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

#define N 105
double dp[N][N][N][3];

int main() {
    int r,s,p;
    RI(r,s,p);
    REP1(i,0,r) REP1(j,0,s) REP1(k,0,p) {
        double *me=dp[i][j][k];
        if ( i+j+k==0 ) continue;
        if ( j+k==0 ) me[0]=1;
        else if ( i+k==0 ) me[1]=1;
        else if ( i+j==0 ) me[2]=1;
        else {
            double all=i*j+i*k+j*k;
            double pij=i*j/all;
            double pik=i*k/all;
            double pjk=j*k/all;
            if ( pij>0 ) REP(l,3) me[l]+=pij*dp[i][j-1][k][l];
            if ( pik>0 ) REP(l,3) me[l]+=pik*dp[i-1][j][k][l];
            if ( pjk>0 ) REP(l,3) me[l]+=pjk*dp[i][j][k-1][l];
        }
    }
    double *ans=dp[r][s][p];
    printf("%.12f %.12f %.12f\n",ans[0],ans[1],ans[2]);
    return 0;
}