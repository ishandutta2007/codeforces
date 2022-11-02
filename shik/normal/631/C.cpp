// {{{ by shik
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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int N=2e5+10;

namespace treap {
    const int INF=0x7FFFFFFF;
    int my_rand() {
        static int seed;
        return seed=seed*1103515245+12345;
    }
    struct Treap {
        static Treap mem[N],*pmem;
        Treap *l,*r;
        int rnd,size,val,sml,add;
        bool rev;
        Treap() {}
        Treap( int _val ):l(NULL),r(NULL),rnd(my_rand()),size(1),val(_val),sml(_val),add(0),rev(false) {}
    } Treap::mem[N],*Treap::pmem=Treap::mem;
    inline int size( Treap *t ) { return t?t->size:0; }
    inline int sml( Treap *t ) { return t?t->sml+t->add:INF; }
    void debug( Treap *t, int indent=0 ) {
        REP(i,indent) putchar(' ');
        if ( !t ) puts("NULL");
        else {
            printf("rnd=%d, size=%d, val=%d, sml=%d, add=%d, rev=%d\n",t->rnd,t->size,t->val,t->sml,t->add,(int)t->rev);
            debug(t->l,indent+4);
            debug(t->r,indent+4);
        }
    }
    inline void push( Treap *t ) {
        if ( !t ) return;
        if ( t->rev ) {
            if ( t->l ) t->l->rev^=1;
            if ( t->r ) t->r->rev^=1;
            swap(t->l,t->r);
            t->rev=false;
        }
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
        t->sml=min(t->val,min(sml(t->l),sml(t->r)));
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
    void dfs( Treap *t, vector<int> &out ) {
        if ( !t ) return;
        push(t);
        dfs(t->l,out);
        out.PB(t->val);
        dfs(t->r,out);
    }
}

using namespace treap;
Treap *root=NULL,*tl=NULL,*tr=NULL;

void rev( int l, int r ) {
    dump(l,r);
    split(root,l-1,tl,root);
    split(root,r-l+1,root,tr);
    root->rev^=1;
    root=merge(tl,root);
    root=merge(root,tr);
}

int n,m,a[N],t[N],r[N];
int main() {
    R(n,m);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,m) R(t[i],r[i]);
    vector<int> v;
    v.PB(m);
    for ( int i=m-1; i>=1; i-- ) if ( r[i]>r[v.back()] ) v.PB(i);
    reverse(ALL(v));
    dump(v);
    if ( t[v[0]]==1 ) sort(a+1,a+r[v[0]]+1);
    else sort(a+1,a+r[v[0]]+1,greater<int>());
    REP1(i,1,n) root=merge(root,new (Treap::pmem++) Treap(a[i]));
    REP1(i,1,SZ(v)-1) if ( t[v[i]]!=t[v[i-1]] ) {
        int ri=r[v[i]];
        rev(1,ri);
        // reverse(a+1,a+ri+1);
    }
    vector<int> ans;
    dfs(root,ans);
    W(ans);
    // assert(ans==VI(a+1,a+n+1));
    return 0;
}