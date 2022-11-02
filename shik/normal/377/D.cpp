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

#define M 1200010
#define INF 514514514
struct Seg {
    int add[M],big[M];
    void init( int id, int l, int r ) {
        add[id]=big[id]=0;
        if ( l==r ) return;
        int m=(l+r)/2;
        init(id*2,l,m);
        init(id*2+1,m+1,r);
    }
    void push( int id ) {
        add[id*2]+=add[id];
        add[id*2+1]+=add[id];
        add[id]=0;
    }
    void pull( int id ) {
        big[id]=max(big[id*2]+add[id*2],big[id*2+1]+add[id*2+1]);
    }
    void ins( int id, int l, int r, int ql, int qr, int qv ) {
        if ( qr<l || ql>r ) return;
        if ( ql<=l && r<=qr ) {
            add[id]+=qv;
            return;
        }
        push(id);
        int m=(l+r)/2;
        ins(id*2,l,m,ql,qr,qv);
        ins(id*2+1,m+1,r,ql,qr,qv);
        pull(id);
    }
    int ask( int id, int l, int r, int ql, int qr ) {
        if ( qr<l || ql>r ) return -INF;
        if ( ql<=l && r<=qr ) return big[id]+add[id];
        push(id);
        int ret=-INF,m=(l+r)/2;
        ret=max(ret,ask(id*2,l,m,ql,qr));
        ret=max(ret,ask(id*2+1,m+1,r,ql,qr));
        pull(id);
        return ret;
    }
} seg;

#define N 100010
struct P {
    int id,l,v,r;
    void read( int _id ) {
        id=_id;
        RIII(l,v,r);
    }
} p[N];

int main() {
    int n;
    RI(n);
    REP(i,n) p[i].read(i+1);
    sort(p,p+n,[]( P a, P b ) { return a.v>b.v; });
    auto cmpl = []( P a, P b ) { return a.l<b.l; };
    priority_queue<P,vector<P>,decltype(cmpl)> q(cmpl);
    const int segn=300000;
    seg.init(1,1,segn);
    int best=-1,best_i=-1;
    REP(i,n) {
        while ( !q.empty() && q.top().l>p[i].v ) {
            P tp=q.top(); q.pop();
            //printf("pop %d\n",tp.id);
            seg.ins(1,1,segn,tp.v,tp.r,-1);
        }
        seg.ins(1,1,segn,p[i].v,p[i].r,+1);
        int now=seg.ask(1,1,segn,p[i].v,p[i].r);
        //printf("%d: id=%d, (%d,%d,%d) %d\n",i,p[i].id,p[i].l,p[i].v,p[i].r,now);
        if ( now>best ) {
            best=now;
            best_i=i;
        }
        q.push(p[i]);
    }
    printf("%d\n",best);
    //printf("== %d\n",best_i);
    auto cmpr = []( P a, P b ) { return a.r>b.r; };
    priority_queue<P,vector<P>,decltype(cmpr)> q2(cmpr);
    for ( int i=best_i; i>=0; i-- ) if ( p[i].l<=p[best_i].v ) {
        while ( !q2.empty() && q2.top().r<p[i].v ) q2.pop();
        q2.push(p[i]);
        if ( SZ(q2)==best ) {
            while ( !q2.empty() ) {
                P tp=q2.top(); q2.pop();
                printf("%d%c",tp.id,q2.empty()?'\n':' ');
            }
            break;
        }
    }
    return 0;
}