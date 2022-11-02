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

#define N 1000010
struct BIT {
    int dat[N];
    void ins( int x ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]++;
    }
    int ask( int x ) {
        int ret=0;
        for ( int i=x; i; i-=i&-i ) ret+=dat[i];
        return ret;
    }
} bit;

struct Seg {
    int l,r,id;
    Seg() {}
    Seg( int _l, int _r, int _id ):l(_l),r(_r),id(_id) {}
    void read() { RII(l,r); }
} seg[N];

inline bool operator <( const Seg &a, const Seg &b ) {
    if ( a.l!=b.l ) return a.l>b.l;
    if ( a.r!=b.r ) return a.r<b.r;
    return a.id<b.id;
}

int ans[N];
int main() {
    int n,m,nnnnnnnn;
    RII(n,m); nnnnnnnn=n;
    REP(i,n) seg[i].read();
    REP(i,n) seg[i].id=-1;
    REP(i,m) {
        int cnt;
        RI(cnt);
        VI ps(cnt+2);
        ps[0]=0;
        ps[cnt+1]=(int)1e6+1;
        REP1(j,1,cnt) RI(ps[j]);
        for ( int j=0; j<=cnt; j++ ) seg[n++]=Seg(ps[j]+1,ps[j+1]-1,i);
    }
    sort(seg,seg+n);
    REP(i,n) {
        if ( seg[i].id==-1 ) bit.ins(seg[i].r);
        else ans[seg[i].id]+=bit.ask(seg[i].r);
    }
    REP(i,m) printf("%d\n",nnnnnnnn-ans[i]);
    return 0;
}