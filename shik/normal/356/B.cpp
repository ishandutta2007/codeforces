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

#define N 1000010
int cnt[N][26];
int main() {
    ios_base::sync_with_stdio(0);
    LL n,m,ans=0;
    string x,y;
    cin>>n>>m>>x>>y;
    int g=__gcd(x.size(),y.size());
    for ( int i=0; i<g; i++ ) for ( int j=i; j<SZ(y); j+=g ) cnt[i][y[j]-'a']++;
    for ( int i=0; i<SZ(x); i++ ) {
        ans+=1LL*(SZ(y)/g-cnt[i%g][x[i]-'a'])*n/(SZ(y)/g);
    }
    cout << ans << endl;
#ifdef SHIK
    string xx,yy;
    while ( n-- ) xx+=x;
    while ( m-- ) yy+=y;
    LL ans2=0;
    REP(i,SZ(xx)) if ( xx[i]!=yy[i] ) ans2++;
    cout << ans2 << endl;
#endif
    return 0;
}