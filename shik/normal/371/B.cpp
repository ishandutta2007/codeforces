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

#define INF 514514514
map<PII,int> dp;
int go( int a, int b ) {
    if ( a>b ) swap(a,b);
    if ( a==b ) return 0;
    PII p=PII(a,b);
    if ( dp.count(p) ) return dp[p];
    int ans=INF;
    if ( a%2==0 ) ans=min(ans,go(a/2,b));
    if ( a%3==0 ) ans=min(ans,go(a/3,b));
    if ( a%5==0 ) ans=min(ans,go(a/5,b));
    swap(a,b);
    if ( a%2==0 ) ans=min(ans,go(a/2,b));
    if ( a%3==0 ) ans=min(ans,go(a/3,b));
    if ( a%5==0 ) ans=min(ans,go(a/5,b));
    swap(a,b);
    return dp[p]=ans+1;
}
int main() {
    int a,b;
    RII(a,b);
    int ans=go(a,b);
    printf("%d\n",ans<INF?ans:-1);
    return 0;
}