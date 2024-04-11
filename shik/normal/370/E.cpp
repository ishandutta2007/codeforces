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

#define N 200010
int n,a[N],nxt[N];
set<PII> vis[N];
bool good( int p, int q ) {
    if ( q>5 ) return 0;
    int np=nxt[p];
    if ( np>n ) return 1;
    if ( a[p-1]>a[np] ) return 0;
    int dv=a[np]-a[p-1];
    int di=np-(p-1)-1;
    if ( di/2 < dv-1 ) return 0;
    if ( di/5 > dv ) return 0;
    return 1;
}
bool go( int p, int q ) {
    if ( !good(p,q) ) return 0;
    if ( p>n ) {
        if ( q>=2 && q<=5 ) {
            printf("%d\n",a[n]);
            REP1(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
            return 1;
        }
        return 0;
    }
    if ( vis[p].count(PII(a[p-1],q)) ) return 0;
    vis[p].insert(PII(a[p-1],q));
    if ( a[p] ) {
        if ( a[p-1]==a[p] ) return go(p+1,q+1);
        else if ( q>=2 ) return go(p+1,1);
    } else {
        if ( q>=2 ) {
            a[p]=a[p-1]+1;
            if ( go(p+1,1) ) return 1;
            a[p]=0;
        }
        if ( q<5 ) {
            a[p]=a[p-1];
            if ( go(p+1,q+1) ) return 1;
            a[p]=0;
        }
    }
    return 0;
}
int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    if ( a[1]>1 ) return puts("-1"),0;
    a[1]=1;
    nxt[n+1]=n+1;
    for ( int i=n; i>=1; i-- )
        if ( a[i] ) nxt[i]=i;
        else nxt[i]=nxt[i+1];
    if ( !go(2,1) ) puts("-1");
    return 0;
}