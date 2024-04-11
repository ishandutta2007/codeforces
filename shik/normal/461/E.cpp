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

#define L 100010
typedef unsigned long long ULL;

template<typename T> inline void chkmin( T &a, T b ) { if ( b<a ) a=b; }
template<typename T> inline void chkmax( T &a, T b ) { if ( b>a ) a=b; }

LL n;
char t[L];
vector<string> v[10][4][4];
int e[4][4],dp[100][4][4];
int main() {
    cin>>n;
    scanf("%s",t);
    int m=strlen(t);
    REP1(i,2,9) REP(j,m-i) v[i][t[j]-'A'][t[j+i-1]-'A'].PB(string(t+j+1,t+j+i-1));
    REP(i,10) REP(j,4) REP(k,4) {
        auto &vv=v[i][j][k];
        sort(ALL(vv));
        vv.erase(unique(ALL(vv)),vv.end());
    }
    REP(i,4) REP(j,4) {
        REP1(k,2,9) {
            auto &vv=v[k][i][j];
            if ( k<=2 && SZ(vv)==1 ) continue;
            if ( k>2 && SZ(vv)==(1<<(2*(k-2))) ) continue;
            e[i][j]=k-1;
            break;
        }
    }
    REP(i,100) REP(j,4) REP(k,4) dp[i][j][k]=1e8;
    REP(i,4) dp[0][i][i]=0;
    REP(i,50) REP(j,4) REP(k,4) REP(l,4) chkmin(dp[i+1][j][l],dp[i][j][k]+e[k][l]);
    n--;
    LL ans=0;
    REP1(i,1,4) REP(j,4) {
        int cyc=dp[i][j][j];
        REP(l1,20) {
            int m1=1e8;
            REP(k,4) chkmin(m1,dp[l1][j][k]);
            REP(l2,20) {
                int m2=1e8;
                REP(k,4) chkmin(m2,dp[l2][k][j]);
                LL rem=n-m1-m2;
                if ( rem<0 ) continue;
                LL now=l1+l2+rem/cyc*i;
                chkmax(ans,now);
            }
        }
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}