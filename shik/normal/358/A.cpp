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

bool jiao( int l1, int r1, int l2, int r2 ) {
    if ( l1>r1 ) swap(l1,r1);
    if ( l2>r2 ) swap(l2,r2);
    if ( l1<l2 && l2<r1 && r1<r2 ) return 1;
    if ( l2<l1 && l1<r2 && r2<r1 ) return 1;
    return 0;
}

#define N 1010
int main() {
    int n,x[N];
    RI(n);
    REP(i,n) RI(x[i]);
    bool good=1;
    REP(i,n-1) REP(j,n-1) if ( jiao(x[i],x[i+1],x[j],x[j+1]) ) good=0;
    puts(!good?"yes":"no");
    return 0;
}