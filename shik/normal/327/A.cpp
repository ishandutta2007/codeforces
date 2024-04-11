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

int main() {
    int n,a[110];
    RI(n);
    REP1(i,1,n) RI(a[i]);
    int ans=0;
    for ( int i=1; i<=n; i++ ) for ( int j=i; j<=n; j++ ) {
        for ( int k=i; k<=j; k++ ) a[k]^=1;
        int now=0;
        REP1(k,1,n) now+=a[k];
        ans=max(ans,now);
        for ( int k=i; k<=j; k++ ) a[k]^=1;
    }
    printf("%d\n",ans);
    return 0;
}