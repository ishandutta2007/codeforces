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

inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }
inline void chkmax( int &a, int b ) { if ( b>a ) a=b; }

#define N 5010
int op[N],l[N],r[N],v[N],a[N],b[N];

int main() {
    int n,m;
    RII(n,m);
    REP(i,m) {
        RI(op[i]);
        RIII(l[i],r[i],v[i]);
    }
    REP1(i,1,n) b[i]=1e9;
    REP(i,m) {
        if ( op[i]==1 ) {
            REP1(j,l[i],r[i]) a[j]+=v[i];
        } else {
            REP1(j,l[i],r[i]) chkmin(b[j],v[i]-a[j]);
        }
    }
    bool ok=1;
    memcpy(a,b,sizeof(b));
    REP(i,m) {
        if ( op[i]==1 ) {
            REP1(j,l[i],r[i]) b[j]+=v[i];
        } else {
            int big=-1e9;
            REP1(j,l[i],r[i]) chkmax(big,b[j]);
            if ( big!=v[i] ) ok=0;
        }
    }
    if ( !ok ) {
        puts("NO");
    } else {
        puts("YES");
        REP1(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}