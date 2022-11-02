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

#define N 300010
int ans[N];
int main() {
    int n,m;
    RII(n,m);
    set<int> s;
    REP1(i,1,n) s.insert(i);
    while ( m-- ) {
        int l,r,x;
        RIII(l,r,x);
        while ( 1 ) {
            auto it=s.lower_bound(l);
            if ( it==s.end() || *it>r ) break;
            if ( *it!=x ) ans[*it]=x;
            s.erase(it);
        }
        s.insert(x);
    }
    REP1(i,1,n) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}