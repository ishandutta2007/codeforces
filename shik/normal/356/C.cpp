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

const int INF=1e9;
int c[5];
vector<PII> per;
int solve() {
    int ans=0;
    FOR(it,per) {
        if ( c[1]==0 && c[2]==0 ) break;
        int a=it->first;
        int b=it->second;
        int t=min(c[a],c[b]);
        if ( a==b ) t/=2;
        ans+=t;
        c[a]-=t;
        c[b]-=t;
        c[a-1]+=t;
        c[b+1]+=t;
    }
    if ( c[1] || c[2] ) return INF;
    return ans;
}
int solve2() {
    int ans=INF;
    for ( int i=0; i<=c[1]; i++ ) {
        // i + 2*j
        // 2*(c[1]-i) + (c[2]-j)
        int mj=(2*c[1]+c[2]-3*i)/3;
        for ( int j=max(mj-10,0); j<=min(mj+10,c[2]); j++ ) {
            int a=i+2*j;
            int b=2*(c[1]-i)+(c[2]-j);
            int now=max(a,b);
            if ( a+c[4]>=b && b+(c[1]-i)+(c[2]-j)+c[3]>=a ) ans=min(ans,now);
        }
    }
    return ans;
}
int main() {
    int n,cc[5]={};
    RI(n);
    REP(i,n) {
        int x;
        RI(x);
        cc[x]++;
    }
    int ans=INF;
    REP1(i,1,4) REP1(j,1,3) if ( j!=i-1 ) per.PB(PII(i,j));
    sort(ALL(per));
    do {
        REP(i,5) c[i]=cc[i];
        ans=min(ans,solve());
    } while ( next_permutation(ALL(per)) );
    REP(i,5) c[i]=cc[i];
    ans=min(ans,solve2());
    if ( ans==INF ) ans=-1;
    printf("%d\n",ans);
    return 0;
}