// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

#define N 2010
#define MOD 1000000007
int n,m;
LL dp[N][N][2];
char s[N];
int main() {
    RII(n,m);
    scanf("%s",s);
    dp[0][0][0]=1;
    REP(i,n) REP(j,m+1) REP(k,2) {
        dp[i][j][k]%=MOD;
        LL me=dp[i][j][k];
        dp[i+1][j][0]+=(s[i]-'a')*me;
        dp[i+1][j][1]+=me;
        if ( k==0 ) {
            int l;
            for ( l =1; i+l<=n && j+l*(n-i-l+1)<=m; l++ ) dp[i+l][j+l*(n-i-l+1)][0]+=('z'-s[i+l-1])*me;
            int _l=l;
            for ( l=n-i; l>=_l && j+l*(n-i-l+1)<=m; l-- ) dp[i+l][j+l*(n-i-l+1)][0]+=('z'-s[i+l-1])*me;
        }
    }
    int ans=(dp[n][m][0]+dp[n][m][1])%MOD;
    printf("%d\n",ans);
    return 0;
}