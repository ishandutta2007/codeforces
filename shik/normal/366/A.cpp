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

int main() {
    int n,x[4][4],y[4][2],z[4];
    RI(n);
    REP(i,4) REP(j,4) RI(x[i][j]);
    REP(i,4) REP(j,2) y[i][j]=min(x[i][2*j],x[i][2*j+1]);
    REP(i,4) z[i]=y[i][0]+y[i][1];
    int w=min_element(z,z+4)-z;
    if ( n<z[w] ) puts("-1");
    else printf("%d %d %d\n",w+1,y[w][0],n-y[w][0]);
    return 0;
}