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

int n,a[N],m,b[N],dp[N],frm[N];
int main() {
    RI(n);
    REP(i,n) RI(a[i]);
    RI(m);
    REP(i,m) RI(b[i]);
    REP(i,n) {
        int mx=0,wh=-1;
        REP(j,m) {
            if ( a[i]==b[j] ) {
                dp[j]=mx+1;
                frm[j]=wh;
            } else if ( a[i]>b[j] && dp[j]>mx ) {
                mx=dp[j];
                wh=j;
            }
        }
    }
    int p=max_element(dp,dp+m)-dp;
    printf("%d\n",dp[p]);
    if ( dp[p]==0 ) {
        puts("");
    } else {
        VI sol;
        while ( p!=-1 ) {
            sol.PB(b[p]);
            p=frm[p];
        }
        reverse(ALL(sol));
        REP(i,SZ(sol)) printf("%d%c",sol[i],i+1==SZ(sol)?'\n':' ');
    }
    return 0;
}