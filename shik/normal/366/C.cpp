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
#define REP(i,n) for (int i=0; i<(int)(n); i++)
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

inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }
#define N 110
int a[N],b[N];
map<int,int> dp[N];
int main() {
    int n,k;
    RII(n,k);
    REP(i,n) RI(a[i]);
    REP(i,n) RI(b[i]);
    dp[0][0]=0;
    REP(i,n) FOR(it,dp[i]) {
        chkmax(dp[i+1][it->first],it->second);
        chkmax(dp[i+1][it->first+a[i]-k*b[i]],it->second+a[i]);
    }
    printf("%d\n",dp[n][0]?dp[n][0]:-1);
    return 0;
}