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
    int n,m;
    RII(n,m);
    int cnt[110]={};
    REP(i,n) {
        int c;
        RI(c);
        cnt[c]++;
    }
    vector<PII> sol;
    int ans=0,rem=n;
    while ( 1 ) {
        int w1=0,w2=0,w3=0;
        REP1(i,1,m) {
            if ( cnt[i]>=cnt[w1] ) {
                w3=w2;
                w2=w1;
                w1=i;
            } else if ( cnt[i]>=cnt[w2] ) {
                w3=w2;
                w2=i;
            } else if ( cnt[i]>=cnt[w3] ) w3=i;
        }
        if ( cnt[w1]==0 ) break;
        if ( cnt[w2]==0 ) {
            sol.PB(PII(w1,w1));
            cnt[w1]--;
            rem--;
        } else if ( rem==3 && cnt[w3] ) {
            ans+=3;
            sol.PB(PII(w1,w2));
            sol.PB(PII(w2,w3));
            sol.PB(PII(w3,w1));
            cnt[w1]--;
            cnt[w2]--;
            cnt[w3]--;
            rem-=3;
        } else {
            ans+=2;
            sol.PB(PII(w1,w2));
            sol.PB(PII(w2,w1));
            cnt[w1]--;
            cnt[w2]--;
            rem-=2;
        }
    }
    printf("%d\n",ans);
    FOR(it,sol) printf("%d %d\n",it->first,it->second);
    return 0;
}