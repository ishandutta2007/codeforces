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

#define N 110
int n,m[N],a[N][N];
int main() {
    RI(n);
    REP(i,n) {
        RI(m[i]);
        REP(j,m[i]) RI(a[i][j]);
    }
    REP(i,n) {
        bool v[110]={};
        REP(j,m[i]) v[a[i][j]]=1;
        bool win=1;
        REP(j,n) if ( i!=j ) {
            bool flg=1;
            REP(k,m[j]) flg&=v[a[j][k]];
            win&=!flg;
        }
        puts(win?"YES":"NO");
    }
    return 0;
}