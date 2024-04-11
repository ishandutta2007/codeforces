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

const int N=1010;
const int M=N*N/2;

struct DJS {
    int fa[N],cl[N],rk[N];
    vector<pair<int*,int>> hs;
    void init( int n ) {
        REP1(i,1,n) {
            fa[i]=i;
            rk[i]=1;
        }
    }
    PII Find( int x ) {
        int c=0;
        while ( fa[x]!=x ) {
            c^=cl[x];
            x=fa[x];
        }
        return {x,c};
    }
    void z( int &k, int v ) {
        hs.PB({&k,k});
        k=v;
    }
    void Union( int ra, int ca, int rb, int cb ) {
        if ( rk[ra]>rk[rb] ) {
            swap(ra,rb);
            swap(ca,cb);
        }
        z(fa[ra],rb);
        z(cl[ra],ca^cb^1);
        if ( rk[ra]==rk[rb] ) z(rk[rb],rk[rb]+1);
    }
    void clear() {
        while ( !hs.empty() ) {
            auto &h=hs.back();
            *h.first=h.second;
            hs.pop_back();
        }
    }
} djs;

struct E {
    int a,b,c;
} e[M];

int test( int x ) {
    int ra,ca,rb,cb;
    tie(ra,ca)=djs.Find(e[x].a);
    tie(rb,cb)=djs.Find(e[x].b);
    if ( ra==rb ) return ca==cb?-1:0;
    djs.Union(ra,ca,rb,cb);
    return 1;
}

VI merge( const VI &a, const VI &b ) {
    djs.clear();
    int na=SZ(a),nb=SZ(b);
    VI c;
    int ia=0,ib=0;
    while ( ia<na || ib<nb ) {
        int x;
        if ( ib==nb || (ia<na && e[a[ia]].c>e[b[ib]].c) ) x=a[ia++];
        else x=b[ib++];
        int y=test(x);
        if ( y!=0 ) c.PB(x);
        if ( y==-1 ) break;
    }
    return c;
}

struct Seg {
    VI dat[4*M];
    void init( int id, int l, int r ) {
        if ( l==r ) {
            dat[id].PB(l);
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m);
        init(id*2+1,m+1,r);
        dat[id]=merge(dat[id*2],dat[id*2+1]);
    }
    void ask( int id, int l, int r, int ql, int qr, VI &qv ) {
        if ( ql<=l && r<=qr ) {
            qv=merge(qv,dat[id]);
            return;
        }
        int m=(l+r)/2;
        if ( ql<=m ) ask(id*2,l,m,ql,qr,qv);
        if ( qr>m ) ask(id*2+1,m+1,r,ql,qr,qv);
    }
} seg;

int n,m,q;
int main() {
    R(n,m,q);
    REP1(i,1,m) R(e[i].a,e[i].b,e[i].c);
    djs.init(n);
    seg.init(1,1,m);
    while ( q-- ) {
        int l,r;
        R(l,r);
        VI v;
        seg.ask(1,1,m,l,r,v);
        djs.clear();
        int ans=-1;
        for ( int i:v ) {
            if ( test(i)==-1 ) {
                ans=e[i].c;
                break;
            }
        }
        W(ans);
    }
    return 0;
}