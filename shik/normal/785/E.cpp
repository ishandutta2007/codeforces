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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

struct SplitMix32 {
    uint32_t s;
    SplitMix32(uint32_t _s = 0) : s(_s) {}
    uint32_t operator()() {
        uint32_t z = (s += 0x9e3779b1);
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
} rnd;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;

struct SegTreeRangeAsk {
    int n;
    vector<set_t> dat;
    void init(int id, int l, int r, int *a) {
        dat[id]=set_t(a+l,a+r+1);
        if (l == r) return;
        int m = (l + r) / 2;
        init(id * 2, l, m, a);
        init(id * 2 + 1, m + 1, r, a);
    }
    void init(int _n, int *a) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, a);
    }
    int ask(int id, int l, int r, int ql, int qr, int qlo, int qhi) {
        if (ql <= l && r <= qr) {
            int clo = dat[id].order_of_key(qlo);
            int chi = dat[id].order_of_key(qhi + 1);
            // VI v(dat[id].begin(),dat[id].end());
            // dump(id,l,r,ql,qr,qlo,qhi,clo,chi,v);
            return chi - clo;
        }
        int m = (l + r) / 2;
        if (qr <= m) return ask(id * 2, l, m, ql, qr, qlo, qhi);
        if (ql > m) return ask(id * 2 + 1, m + 1, r, ql, qr, qlo, qhi);
        int tl = ask(id * 2, l, m, ql, qr, qlo, qhi);
        int tr = ask(id * 2 + 1, m + 1, r, ql, qr, qlo, qhi);
        return tl + tr;
    }
    int ask(int l, int r, int lo, int hi) {
        return ask(1, 1, n, l, r, lo, hi);
    }
    void chg(int id, int l, int r, int qx, int qu, int qv) {
        auto iu=dat[id].find(qu);
        auto iv=dat[id].find(qv);
        if ( iu!=dat[id].end() && iv==dat[id].end() ) {
            dat[id].erase(iu);
            dat[id].insert(qv);
        } else if ( iv!=dat[id].end() && iu==dat[id].end() ) {
            dat[id].erase(iv);
            dat[id].insert(qu);
        }
        assert(SZ(dat[id])==r-l+1);
        if (l == r) return;
        int m = (l + r) / 2;
        if (qx <= m) chg(id * 2, l, m, qx, qu, qv);
        else chg(id * 2 + 1, m + 1, r, qx, qu, qv);
    }
    void chg(int qx, int qu, int qv) {
        assert(1 <= qx && qx <= n);
        chg(1, 1, n, qx, qu, qv);
    }
} seg;


const int N=2e5+10;

int n,m,a[N];
int main() {
    // n=200000;
    // m=50000;
    R(n,m);
    REP1(i,1,n) a[i]=i;
    seg.init(n, a);
    LL ans=0;
    while ( m-- ) {
        int x,y;
        R(x,y);
        // x=rnd()%n+1;
        // y=rnd()%n+1;
        if ( x==y ) {
            W(ans);
            continue;
        }
        if ( x>y ) swap(x,y);
        int lo=min(a[x],a[y]);
        int hi=max(a[x],a[y]);
        int t=seg.ask(x,y,lo,hi)-2;
        // dump(x,y,t,VI(a+1,a+n+1));
        if ( a[x]<a[y] ) ans+=2*t+1;
        else ans-=2*t+1;
        assert(ans>=0);
        W(ans);
        seg.chg(x,a[x],a[y]);
        seg.chg(y,a[y],a[x]);
        swap(a[x],a[y]);
    }
    fflush(stdout);
    _exit(0);
    return 0;
}