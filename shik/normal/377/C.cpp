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

inline int bit( int x, int i ) { return (x>>i)&1; }
inline int two( int x ) { return 1<<x; }

#define N 110
#define INF 514514514
int n,s[N],m,team[N],dp[20][1<<20];
char op[N];
bool vis[20][1<<20];

int go( int mi, int ban ) {
    if ( mi==m ) return 0;
    int &ret=dp[mi][ban];
    if ( vis[mi][ban] ) return ret;
    vis[mi][ban]=1;
    ret=-INF;
    REP(i,n) if ( !bit(ban,i) ) {
        int now=go(mi+1,ban|two(i));
        int str=(op[mi]=='p'?s[i]:0);
        if ( mi+1<m && team[mi+1]!=team[mi] ) now=str-now;
        else now=str+now;
        ret=max(ret,now);
    }
    return ret;
}

int main() {
    RI(n);
    REP(i,n) RI(s[i]);
    RI(m);
    REP(i,m) scanf(" %c %d",op+i,team+i);
    sort(s,s+n,greater<int>());
    n=m;
    int ans=go(0,0);
    if ( team[0]==2 ) ans*=-1;
    printf("%d\n",ans);
    return 0;
}