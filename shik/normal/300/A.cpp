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
    VI v[3];
    int n;
    RI(n);
    while ( n-- ) {
        int x;
        RI(x);
        if ( x<0 ) v[0].PB(x);
        else if ( x>0 ) v[1].PB(x);
        else v[2].PB(x);
    }
    if ( SZ(v[0])%2==0 ) {
        v[2].PB(v[0].back());
        v[0].pop_back();
    }
    if ( v[1].empty() ) {
        v[1].PB(v[0].back());
        v[0].pop_back();
        v[1].PB(v[0].back());
        v[0].pop_back();
    }
    REP(i,3) {
        printf("%d",SZ(v[i]));
        FOR(it,v[i]) printf(" %d",*it);
        puts("");
    }
    return 0;
}