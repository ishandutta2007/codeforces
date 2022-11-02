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

#define N 3010
int dis[N][N];
bool vis[N][N];
int n,k,p[N],pp[N];
int main() {
    RII(n,k);
    REP1(i,1,n) RI(p[i]);
    for ( int i=n; i>=1; i-- ) pp[i]=max(pp[i+1],p[i]);
    queue<int> q;
    auto push = [&]( int a, int b, int d ) {
        if ( vis[a][b] ) return;
        q.push(a);
        q.push(b);
        vis[a][b]=1;
        dis[a][b]=d;
    };
    push(1,2,0);
    while ( !q.empty() ) {
        int a=q.front(); q.pop();
        int b=q.front(); q.pop();
        if ( b>n ) continue;
        bool a0=(pp[b]>0);
        bool a1=(pp[b]<100);
        bool b0=(p[a]>0);
        bool b1=(p[a]<100);
        int nd=dis[a][b]+1;
        if ( a0 && b0 ) push(b+1,b+2,nd);
        if ( a0 && b1 ) push(b,b+1,nd);
        if ( a1 && b0 ) push(a,b+1,nd);
    }
    int ans=0;
    REP(i,N) REP(j,N) if ( vis[i][j] && dis[i][j]<=k ) ans++;
    printf("%d\n",ans);
    return 0;
}