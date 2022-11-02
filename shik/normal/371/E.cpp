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

#define N 300010
int n,m;
LL s[N];
PII p[N];
int main() {
    RI(n);
    REP1(i,1,n) {
        RI(p[i].first);
        p[i].second=i;
    }
    RI(m);
    sort(p+1,p+n+1);
    REP1(i,1,n) s[i]=s[i-1]+p[i].first;
    LL now=0;
    REP1(i,1,m) now+=1LL*p[i].first*(i-1)-s[i-1];
    LL sml=now;
    int who=1;
    REP1(i,2,n) if ( i+m-1<=n ) {
        // [i-1, i+m-2] => [i, i+m-1]
        now-=s[i+m-2]-s[i-1]-1LL*p[i-1].first*(m-1);
        now+=1LL*p[i+m-1].first*(m-1)-(s[i+m-2]-s[i-1]);
        if ( now<sml ) {
            sml=now;
            who=i;
        }
    }
    REP(i,m) printf("%d%c",p[who+i].second,i+1==m?'\n':' ');
    return 0;
}