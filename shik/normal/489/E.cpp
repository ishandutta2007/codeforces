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

inline void chkmin( double &a, double b ) {
    if ( b<a ) a=b;
}

#define N 1010
int n,l,x[N],b[N];
double d[N][N];

double dp[N];
bool chk( double m ) {
    dp[0]=0;
    REP1(i,1,n) {
        double mi=1e100;
        REP1(j,0,i-1) chkmin(mi,dp[j]+d[j][i]);
        dp[i]=mi-m*b[i];
    }
    return dp[n]<=0;
}

int frm[N];
void trace( double m ) {
    dp[0]=0;
    REP1(i,1,n) {
        double mi=1e100;
        REP1(j,0,i-1) if ( dp[j]+d[j][i]<mi ) {
            mi=dp[j]+d[j][i];
            frm[i]=j;
        }
        dp[i]=mi-m*b[i];
    }
    VI sol;
    for ( int i=n; i; i=frm[i] ) sol.PB(i);
    reverse(ALL(sol));
    REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
}

int main() {
    RI(n,l);
    REP1(i,1,n) RI(x[i],b[i]);
    REP1(i,0,n) REP1(j,i+1,n) d[i][j]=sqrt((double)abs(x[j]-x[i]-l));
    double ll=0,rr=1e9;
    REP(i,100) {
        double mm=(ll+rr)/2;
        if ( chk(mm) ) rr=mm;
        else ll=mm;
    }
    double mm=(ll+rr)/2;
    trace(mm);
    return 0;
}