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

struct SCC {
    int n;
    vector<vector<int>> e1, e2, scc;
    vector<int> grp, ord;
    void init(int _n) {
        n = _n;
        e1.clear();
        e1.resize(n);
        e2.clear();
        e2.resize(n);
    }
    void add(int a, int b) {
        e1[a].push_back(b);
        e2[b].push_back(a);
    }
    void dfs1(int u) {
        grp[u] = -1;
        for (int v : e1[u]) if (grp[v] == 0) dfs1(v);
        ord.push_back(u);
    }
    void dfs2(int u) {
        grp[u] = scc.size() - 1;
        scc.back().push_back(u);
        for (int v : e2[u]) if (grp[v] == -1) dfs2(v);
    }
    void solve() {
        grp.clear();
        grp.resize(n);
        ord.clear();
        ord.reserve(n);
        for (int i = 0; i < n; i++) if (grp[i] == 0) dfs1(i);
        reverse(ord.begin(), ord.end());
        scc.clear();
        grp.resize(n);
        for (int i : ord) if (grp[i] == -1) {
            scc.emplace_back();
            dfs2(i);
        }
    }
};

struct TwoSAT {
    int n;
    vector<bool> var;
    SCC scc;
    void init(int _n) {
        n = _n;
        scc.init(2 * n);
    }
    int inv(int x) {
        return x < n ? x + n : x - n;
    }
    void add(int a, int b) {
        scc.add(a, b);
        scc.add(inv(b), inv(a));
    }
    void add(int a, int x, int b, int y) {
        add(a + x * n, b + y * n);
    }
    bool solve() {
        scc.solve();
        var.clear();
        for (int i = 0; i < n; i++) if (scc.grp[i] == scc.grp[i + n]) return false;
        var.resize(n);
        for (int i = 0; i < n; i++) var[i] = (scc.grp[i + n] > scc.grp[i]);
        return true;
    }
} sat;

const int N=2e5+10;
int n,m,x[N];
VI e[N];

int main() {
    R(n,m);
    REP(i,n) R(x[i]);
    REP(i,m) {
        int l;
        R(l);
        REP(j,l) {
            int t;
            R(t);
            t--;
            e[t].PB(i);
        }
    }
    sat.init(m);
    REP(i,n) {
        assert(SZ(e[i])==2);
        int a=e[i][0],b=e[i][1];
        if ( x[i]==1 ) {
            sat.add(a,0,b,0);
            sat.add(a,1,b,1);
        } else {
            sat.add(a,0,b,1);
            sat.add(a,1,b,0);
        }
    }
    W(sat.solve() ? "YES" : "NO");
    return 0;
}