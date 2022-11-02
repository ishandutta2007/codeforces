// {{{ by shik
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

template<typename T>
struct Seg {
    int n;
    vector<T> dat;
    void init(int id, int l, int r, T *a) {
        if (l == r) {
            dat[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        init(id * 2, l, m, a);
        init(id * 2 + 1, m + 1, r, a);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    void init(int _n, T *a) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, a);
    }
    int ask(int id, int l, int r, int q) {
        // dump(id, l, r, q, dat[id]);
        if (q > dat[id].y) return 0;
        if (l == r) return l;
        int m = (l + r) / 2;
        if (q <= dat[id * 2 + 1].y) return ask(id * 2 + 1, m + 1, r, q);
        else return ask(id * 2, l, m, q - dat[id * 2 + 1].y + dat[id * 2 + 1].x);
    }
    int ask(int q) {
        return ask(1, 1, n, q);
    }
    void chg(int id, int l, int r, int qx, T qv) {
        if (l == r) {
            dat[id] = qv;
            return;
        }
        int m = (l + r) / 2;
        if (qx <= m) chg(id * 2, l, m, qx, qv);
        else chg(id * 2 + 1, m + 1, r, qx, qv);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
        // dump(id,l,r,qx,qv,dat[id]);
    }
    void chg(int qx, T qv) {
        assert(1 <= qx && qx <= n);
        chg(1, 1, n, qx, qv);    
    }
};

struct P {
    int x,y;
};

ostream& operator<<( ostream &os, const P &p ) {
    return os<<'('<<p.x<<','<<p.y<<')';
}

inline P operator +( const P &a, const P &b ) {
    int x=a.x;
    int y=b.y;
    int d=a.y-b.x;
    if ( d<0 ) x+=-d;
    else y+=d;
    return {x,y};
}

const int N=1e5+10;
int n,p[N],t[N],x[N],y[N];
P a[N];
Seg<P> seg;
int main() {
    R(n);
    REP1(i,1,n) {
        R(p[i],t[i]);
        if ( t[i]==1 ) {
            R(x[i]);
            y[p[i]]=x[i];
        }
    }
    seg.init(n,a);
    y[0]=-1;
    REP1(i,1,n) {
        if ( t[i]==0 ) a[p[i]]={1,0};
        else a[p[i]]={0,1};
        seg.chg(p[i],a[p[i]]);
        int idx=seg.ask(1);
        W(y[idx]);
    }
    return 0;
}