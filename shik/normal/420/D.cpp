// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define ALL(x) begin(x),end(x)
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}


#define N 1000010

vector<int> sol;

namespace treap {
    const int INF=0x7FFFFFFF;
    int my_rand() {
        static int seed;
        return seed=seed*1103515245+12345;
    }
    struct Treap {
        static Treap mem[N],*pmem;
        Treap *l,*r;
        int rnd,size,val;
        bool rev;
        Treap() {}
        Treap( int _val ):l(NULL),r(NULL),rnd(my_rand()),size(1),val(_val) {}
    } Treap::mem[N],*Treap::pmem=Treap::mem;
    inline int size( Treap *t ) { return t?t->size:0; }
    inline void pull( Treap *t ) {
        if ( !t ) return;
        t->size=size(t->l)+size(t->r)+1;
    }
    Treap* merge( Treap *a, Treap *b ) {
        if ( !a || !b ) return a?a:b;
        if ( a->rnd < b->rnd ) {
            a->r=merge(a->r,b);
            pull(a);
            return a;
        } else {
            b->l=merge(a,b->l);
            pull(b);
            return b;
        }
    }
    void split( Treap *t, int k, Treap *&a, Treap *&b ) {
        if ( !t ) a=b=NULL;
        else if ( k<=size(t->l) ) {
            b=t;
            split(t->l,k,a,b->l);
            pull(b);
        } else {
            a=t;
            split(t->r,k-size(t->l)-1,a->r,b);
            pull(a);
        }
    }
    void inorder( Treap *t ) {
        if ( t->l ) inorder(t->l);
        sol.PB(t->val);
        if ( t->r ) inorder(t->r);
    }
}

using namespace treap;

int n,m,x[N],y[N];
bool used[N];

int main() {
    RI(n,m);
    REP(i,m) RI(x[i],y[i]);
    Treap *t=NULL,*tl,*tr;
    REP(i,n) t=merge(t,new (Treap::pmem++) Treap(0));
    bool good=1;
    for ( int i=m-1; i>=0; i-- ) {
        split(t,1,tl,t);
        split(t,y[i]-1,t,tr);
        if ( tl->val ) good&=(tl->val==x[i]);
        else {
            good&=!used[x[i]];
            used[x[i]]=1;
            tl->val=x[i];
        }
        t=merge(t,merge(tl,tr));
    }
    if ( !good ) {
        puts("-1");
    } else {
        sol.reserve(n);
        inorder(t);
        int cur=1;
        for (auto &c : sol) if ( c==0 ) {
            while ( used[cur] ) cur++;
            used[cur]=1;
            c=cur;
        }
        REP(i,n) printf("%d%c",sol[i],i+1==n?'\n':' ');
    }
    return 0;
}