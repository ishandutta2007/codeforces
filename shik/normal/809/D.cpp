// {{{ by shik
#ifndef YCM
#pragma GCC optimize("O3")
#endif
#include <stdio.h>
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const long long &x ) { printf("%" PRId64,x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int N=6e5+10;
const int INF=1e9+10;

struct SplitMix32 {
    uint32_t s;
    SplitMix32(uint32_t _s = 0) : s(_s) {}
    uint32_t operator()() {
        uint32_t z = (s += 0x9e3779b1);
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
} my_rand;

namespace treap {
    struct Treap {
        static Treap mem[N],*pmem;
        Treap *l,*r;
        uint32_t rnd;
        int size,val,big,add;
        Treap() {}
        Treap( int _val ):l(NULL),r(NULL),rnd(my_rand()),size(1),val(_val),big(_val),add(0) {}
    } Treap::mem[N],*Treap::pmem=Treap::mem;
    inline int size( Treap *t ) { return t?t->size:0; }
    inline int big( Treap *t ) { return t?t->big+t->add:-INF; }
    void debug( Treap *t, int indent=0 ) {
        REP(i,indent) putchar(' ');
        if ( !t ) puts("NULL");
        else {
            printf("rnd=%d, size=%d, val=%d, big=%d, add=%d\n",t->rnd,t->size,t->val,t->big,t->add);
            debug(t->l,indent+4);
            debug(t->r,indent+4);
        }
    }
    inline void push( Treap *t ) {
        if ( !t ) return;
        if ( t->add ) {
            if ( t->l ) t->l->add+=t->add;
            if ( t->r ) t->r->add+=t->add;
            t->val+=t->add;
            t->add=0;
        }
    }
    inline void pull( Treap *t ) {
        if ( !t ) return;
        t->size=size(t->l)+size(t->r)+1;
        t->big=max(t->val,max(big(t->l),big(t->r)));
    }
    Treap* merge( Treap *a, Treap *b ) {
        if ( !a || !b ) return a?a:b;
        if ( a->rnd < b->rnd ) {
            push(a);
            a->r=merge(a->r,b);
            pull(a);
            return a;
        } else {
            push(b);
            b->l=merge(a,b->l);
            pull(b);
            return b;
        }
    }
    void split( Treap *t, int k, Treap *&a, Treap *&b ) {
        push(t);
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
    // 1 + (#a_i < x)
    int rnk( Treap *t, int x ) {
        push(t);
        if ( !t ) return 1;
        else if ( x<=t->val ) return rnk(t->l,x);
        else return size(t->l)+1+rnk(t->r,x);
    }
}
    
using namespace treap;

Treap *tl,*root,*tr;
void split_range( int l, int r ) {
    split(root,l-1,tl,root);
    split(root,r-l+1,root,tr);
}
void merge_range() {
    root=merge(tl,root);
    root=merge(root,tr);
}

int n,ll[N],rr[N];

void slow() {
    VI v;
    REP1(i,1,n) for ( int j=rr[i]; j>=ll[i]; j-- ) {
        if ( v.empty() || j>v.back() ) v.PB(j);
        else *lower_bound(ALL(v),j)=j;
    }
    dump(SZ(v));
}

int main() {
    R(n);
    REP1(i,1,n) R(ll[i],rr[i]);
    // n=300;
    // REP1(i,1,n) {
        // ll[i]=my_rand()%10000+1;
        // rr[i]=ll[i]+my_rand()%10000;
        // if ( ll[i]>rr[i] ) swap(ll[i],rr[i]);
    // }
    REP1(i,1,n+1) root=merge(root,new (Treap::pmem++) Treap(INF+i));
    REP1(i,1,n) {
        int l=ll[i],r=rr[i];
        int lp=rnk(root,l);
        int rp=rnk(root,r);
        split_range(rp,rp);
        root=merge(tl,tr);
        if ( lp<=rp-1 ) {
            split_range(lp,rp-1);
            root->add++;
            merge_range();
        }
        split(root,lp-1,tl,tr);
        root=merge(tl,merge(new (Treap::pmem++) Treap(l),tr));
    }
    int ans=rnk(root,INF)-1;
    W(ans);
#ifdef SHIK
    slow();
#endif
    return 0;
}