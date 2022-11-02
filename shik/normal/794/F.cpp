// {{{ by shik
#pragma GCC optimize("O3")
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

template<typename T, typename U>
struct Seg {
    int n;
    vector<T> val;
    vector<U> upd;
    template<typename F>
    void init(int id, int l, int r, F f) {
        if (l == r) {
            val[id] = f(l);
            return;
        }
        int m = (l + r) / 2;
        init(id * 2, l, m, f);
        init(id * 2 + 1, m + 1, r, f);
        pull(id);
    }
    void init(int _n, T *a) {
        n = _n;
        val.resize(4 * (n + 1));
        upd.resize(4 * (n + 1));
        init(1, 1, n, [a](int i) { return a[i]; });
    }
    T get( int id ) {
        return upd[id](val[id]);
    }
    void pull(int id) {
        val[id] = get(id * 2) + get(id * 2 + 1);
    }
    void push(int id) {
        upd[id * 2] += upd[id];
        upd[id * 2 + 1] += upd[id];
        upd[id] = U();
    }
    T ask(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return get(id);
        push(id);
        int m = (l + r) / 2;
        T tl, tr;
        if (ql <= m) tl = ask(id * 2, l, m, ql, qr);
        if (qr > m) tr = ask(id * 2 + 1, m + 1, r, ql, qr);
        pull(id);
        return tl + tr;
    }
    T ask(int l, int r) {
        assert(l <= r);
        return ask(1, 1, n, l, r);
    }
    void chg(int id, int l, int r, int ql, int qr, U qv) {
        if (ql <= l && r <= qr) {
            upd[id] += qv;
            return;
        }
        push(id);
        int m = (l + r) / 2;
        if (ql <= m) chg(id * 2, l, m, ql, qr, qv);
        if (qr > m) chg(id * 2 + 1, m + 1, r, ql, qr, qv);
        pull(id);
    }
    void chg(int ql, int qr, U qv) {
        chg(1, 1, n, ql, qr, qv);
    }
};

struct Val {
    LL s[10];
    Val() {
        memset(s,0,sizeof(s));
    }
    Val( int x ) {
        memset(s,0,sizeof(s));
        int p=1;
        while ( x ) {
            int d=x%10;
            s[d]+=p;
            x/=10;
            p*=10;
        }
    }
    Val operator +( Val v ) const {
        REP(i,10) v.s[i]+=s[i];
        return v;
    }
    LL get() {
        LL z=0;
        REP(i,10) z+=i*s[i];
        return z;
    }
};

struct Upd {
    int p[10];
    Upd() { REP(i,10) p[i]=i; }
    Upd( int x, int y ) {
        REP(i,10) p[i]=i;
        p[x]=y;
    }
    Upd operator+( const Upd &u ) const {
        Upd nu;
        REP(i,10) nu.p[i]=u.p[p[i]];
        return nu;
    }
    Upd& operator+=( const Upd &u ) { return *this=*this+u; }
    Val operator()( const Val &v ) const {
        Val nv;
        REP(i,10) nv.s[p[i]]+=v.s[i];
        return nv;
    }
};

Seg<Val,Upd> seg;

const int N=1e5+10;
int n,q,a[N];
Val iv[N];
int main() {
    R(n,q);
    REP1(i,1,n) R(a[i]);
    REP1(i,1,n) iv[i]=Val(a[i]);
    // REP1(i,1,n) dump(i,vector<LL>(ALL(iv[i].s)));
    seg.init(n,iv);
    while ( q-- ) {
        int op;
        R(op);
        if ( op==1 ) {
            int l,r,x,y;
            R(l,r,x,y);
            seg.chg(l,r,Upd(x,y));
        } else if ( op==2 ) {
            int l,r;
            R(l,r);
            auto val=seg.ask(l,r);
            // dump(l,r,vector<LL>(ALL(val.s)));
            auto ans=val.get();
            W(ans);
        } else {
            assert(0);
        }
    }
    return 0;
}