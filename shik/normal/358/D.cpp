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

#define N 3010
int n,a[N],b[N],c[N],sb[N],dp[N];
int eval( int l, int r ) {
    if ( l==r ) {
        if ( r==n ) return a[r];
        else return b[r];
    } else {
        int ret=a[l]+sb[r-1]-sb[l];
        if ( r==n ) ret+=b[r];
        else ret+=c[r];
        return ret;
    }
}
int go( int p ) {
    if ( p==0 ) return 0;
    if ( dp[p]!=-1 ) return dp[p];
    int ret=0;
    REP1(i,1,p) ret=max(ret,go(i-1)+eval(i,p));
    return dp[p]=ret;
}
int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,n) RI(b[i]);
    REP1(i,1,n) RI(c[i]);
    REP1(i,1,n) sb[i]=sb[i-1]+b[i];
    memset(dp,-1,sizeof(dp));
    int ans=go(n);
    printf("%d\n",ans);
    return 0;
}