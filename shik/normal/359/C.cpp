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

#define M 1000000007
LL pw( LL a, LL b ) { return b==0?1:pw(a*a%M,b/2)*(b%2?a:1)%M; }

#define N 100010
int a[N];
int main() {
    int n,p;
    RII(n,p);
    REP(i,n) RI(a[i]);
    LL s=0;
    REP(i,n) s+=a[i];
    int cnt=0,cur=a[n-1];
    bool flag=0;
    for ( int i=n-1; i>=0; i-- ) {
        while ( a[i]<cur ) {
            if ( cnt%p!=0 ) {
                flag=1;
                break;
            }
            cnt/=p;
            cur--;
        }
        if ( flag ) break;
        cnt++;
    }
    while ( !flag && cur>0 && cnt%p==0 ) {
        cnt/=p;
        cur--;
    }
    int ans=pw(p,s-cur);
    cout << ans << endl;
    return 0;
}