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

inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }

#define N 2010
int n,k,a[N];

bool chk( LL m ) {
    static int dp[N];
    REP1(i,1,n) dp[i]=1;
    REP1(i,1,n) {
        if ( dp[i]>=n-k ) return 1;
        REP1(j,i+1,n) {
            LL d=abs(a[i]-a[j]);
            LL dd=d/(j-i)+(d%(j-i)!=0);
            if ( dd<=m ) chkmax(dp[j],dp[i]+1);
        }
    }
    return 0;
}

int main() {
    RII(n,k);
    REP1(i,1,n) RI(a[i]);
    if ( n-k<=1 ) return puts("0"),0;
    LL l=0,r=2e9;
    while ( l!=r ) {
        LL m=(l+r)/2;
        if ( chk(m) ) r=m;
        else l=m+1;
    }
    cout << l << endl;
    return 0;
}