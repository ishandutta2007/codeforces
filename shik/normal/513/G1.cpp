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

#define N 35
#define M 210

typedef long double D;

int n,m,a[N];
D dp[M][N][N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
    if ( n==1 ) return puts("0"),0;
    int base=n*(n+1)/2;
    REP1(t,1,m) REP1(i,1,n) REP1(j,i+1,n) {
        D s=0;
        int sc=0;
        REP1(k,1,j-1) {
            int c=min(min(i,k),j-max(i,k));
            sc+=c;
            s+=c*dp[t-1][k][j];
        }
        REP1(k,i+1,n) {
            int c=min(min(j,k)-i,n+1-max(j,k));
            sc+=c;
            s+=c*dp[t-1][i][k];
        }
        REP1(k,1,i-1) {
            int c=min(k,n+1-j);
            sc+=c;
            s+=c*(1-dp[t-1][k][j-(i-k)]);
        }
        REP1(k,j+1,n) {
            int c=min(i,n+1-k);
            sc+=c;
            s+=c*(1-dp[t-1][i+k-j][k]);
        }
        {
            int c=min(i,n+1-j);
            sc+=c;
            s+=c*(1-dp[t-1][i][j]);
        }
        {
            int c=(i-1)*i/2;
            sc+=c;
            s+=c*dp[t-1][i][j];
        }
        {
            int c=(n-j)*(n-j+1)/2;
            sc+=c;
            s+=c*dp[t-1][i][j];
        }
        {
            int c=(j-i)*(j-i-1)/2;
            sc+=c;
            s+=c*dp[t-1][i][j];
        }
        assert(sc==base);
        dp[t][i][j]=s/base;
    }
    D ans=0;
    REP1(i,1,n) REP1(j,i+1,n) {
        if ( a[i]<a[j] ) ans+=dp[m][i][j];
        else ans+=1-dp[m][i][j];
    }
    printf("%.12f\n",(double)ans);
    return 0;
}