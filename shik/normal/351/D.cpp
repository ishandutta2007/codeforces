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

#define N 100010

struct BIT {
    int dat[N];
    void ins( int x, int v ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
} bit,bit2;

struct Q {
    int id,l,r;
    void read( int _id ) {
        id=_id;
        RII(l,r);
    }
} q[N];

bool operator <( Q a, Q b ) { return a.l<b.l; }

int n,m,a[N],nxt[N],far[N],app[N],ans[N];
int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    RI(m);
    REP(i,m) q[i].read(i);
    for ( int i=n; i>=1; i-- ) {
        nxt[i]=app[a[i]];
        if ( nxt[nxt[i]]==0 ) far[i]=n+1;
        else if ( nxt[i]-i==nxt[nxt[i]]-nxt[i] ) far[i]=far[nxt[i]];
        else far[i]=nxt[nxt[i]];
        app[a[i]]=i;
    }
    REP1(i,1,n) if ( app[a[i]]==i ) {
        bit.ins(i,1);
        bit2.ins(i,+1);
        bit2.ins(far[i],-1);
    }
    sort(q,q+m);
    int j=0;
    REP1(i,1,n) {
        while ( j<m && q[j].l==i ) {
            ans[q[j].id]=bit.ask(q[j].r);
            if ( bit2.ask(q[j].r)==0 ) ans[q[j].id]++;
            j++;
        }
        bit.ins(i,-1);
        bit2.ins(i,-1);
        bit2.ins(far[i],+1);
        if ( nxt[i] ) {
            bit.ins(nxt[i],+1);
            bit2.ins(nxt[i],+1);
            bit2.ins(far[nxt[i]],-1);
        }
    }
    REP(i,m) printf("%d\n",ans[i]);
    return 0;
}