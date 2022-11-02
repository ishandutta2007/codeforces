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

#define N 55
const int M=55*10010;
int c[N];
bool dp[M];
int main() {
    int n,d;
    RII(n,d);
    REP(i,n) RI(c[i]);
    dp[0]=1;
    REP(i,n) for ( int j=M-1; j>=c[i]; j-- ) dp[j]|=dp[j-c[i]];
    int last=0;
    for ( int i=1; i-last<=d; i++ ) if ( dp[i] ) last=i;
    vector<int> v;
    for ( int i=0; i<=last; i++ ) if ( dp[i] ) v.PB(i);
    int step=0;
    for ( int i=0; i<last; i=*(upper_bound(ALL(v),i+d)-1) ) step++;
    printf("%d %d\n",last,step);
    return 0;
}