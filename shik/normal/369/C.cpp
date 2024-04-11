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

#define N 100010
vector<PII> e[N];
vector<int> sol;
bool go( int p, int f, bool z ) {
    bool good=0;
    FOR(it,e[p]) if ( it->first!=f ) good|=go(it->first,p,it->second==2);
    if ( z && !good ) {
        sol.PB(p);
        good=1;
    }
    return good;
}
int main() {
    int n;
    RI(n);
    REP(i,n-1) {
        int a,b,c;
        RIII(a,b,c);
        e[a].PB(MP(b,c));
        e[b].PB(MP(a,c));
    }
    go(1,0,0);
    int ans=SZ(sol);
    printf("%d\n",ans);
    sort(ALL(sol));
    REP(i,ans) printf("%d%c",sol[i],i+1==ans?'\n':' ');
    return 0;
}