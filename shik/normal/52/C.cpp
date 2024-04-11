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

const LL INF = 1e18;

#define N 200010

struct Treap {
    static Treap mem[N], *pmem;
    Treap *l, *r;
    int pri, key;
    LL val, sml, add;
    Treap() {}
    Treap( int _key, LL _val ):l(NULL), r(NULL), pri(rand()), key(_key), val(_val), sml(_val) {}
} Treap::mem[N], *Treap::pmem = Treap::mem;

LL sml( Treap *t ) { return t ? t->sml + t->add : INF; }

void pull( Treap *t ) {
    t->sml = min(t->val, min(sml(t->l), sml(t->r)));
}

void push( Treap *t ) {
    t->val+=t->add;
    if ( t->l ) t->l->add+=t->add;
    if ( t->r ) t->r->add+=t->add;
    t->add=0;
}

Treap* merge( Treap *a, Treap *b ) {
    if ( !a || !b ) return a ? a : b;
    if ( a->pri > b->pri ) {
        push(a);
        a->r = merge(a->r, b);
        pull(a);
        return a;
    } else {
        push(b);
        b->l = merge(a, b->l);
        pull(b);
        return b;
    }
}

void split( Treap *t, int k, Treap *&a, Treap *&b ) {
    if ( !t ) a = b = NULL;
    else if ( t->key <= k ) {
        a = t;
        push(a);
        split(t->r, k, a->r, b);
        pull(a);
    } else {
        b = t;
        push(b);
        split(t->l, k, a, b->l);
        pull(b);
    }
}

int n, a[N];

LL ask( Treap *t, int l, int r ) {
    Treap *tl, *tr;
    split(t, l-1, tl, t);
    split(t, r, t, tr);
    LL ret = sml(t);
    merge(merge(tl, t), tr);
    return ret;
}

void add( Treap *t, int l, int r, int v ) {
    Treap *tl, *tr;
    split(t, l-1, tl, t);
    split(t, r, t, tr);
    t->add += v;
    merge(merge(tl, t), tr);
}

void solve() {
    Treap *t = NULL;
    for ( int i=1; i<=n; i++ ) t = merge(t, new (Treap::pmem++) Treap(i, a[i]));
    int m,l,r,v;
    RI(m); while (getchar()!='\n');
    while ( m-- ) {
        char buf[100];
        gets(buf);
        int op = sscanf(buf,"%d%d%d",&l,&r,&v);
        l++; r++;
        if ( op==2 ) {
            LL ans=INF;
            if ( l>r ) ans=min(ask(t,1,r),ask(t,l,n));
            else ans=ask(t,l,r);
            cout<<ans<<endl;
        } else {
            if ( l>r ) {
                add(t,1,r,v);
                add(t,l,n,v);
            } else {
                add(t,l,r,v);
            }
        }
    }
    Treap::pmem = Treap::mem;
}

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    solve();
    return 0;
}