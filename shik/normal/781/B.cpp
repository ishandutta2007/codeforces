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

// {{{ SCC
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
}; // }}}

// 2SAT {{{
struct TwoSAT {
    int n;
    vector<bool> var;
    SCC scc;
    void init(int _n) {
        n = _n;
        scc.init(2 * n);
    }
    int Not(int x) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-overflow"
        return x < n ? x + n : x - n;
#pragma GCC diagnostic pop
    }
    void require(int x) {
        scc.add(Not(x), x);
    }
    void imply(int a, int b) {
        scc.add(a, b);
        scc.add(Not(b), Not(a));
    }
    void And(int a, int b) {
        require(a);
        require(b);
    }
    void Or(int a, int b) {
        imply(Not(a), b);
    }
    void Xor(int a, int b) {
        imply(a, Not(b));
        imply(Not(a), b);
    }
#define F(name) void name(int a, bool x, int b, bool y) { name(a + (1 - x) * n, b + (1 - y) * n); }
    F(imply) F(And) F(Or) F(Xor)
#undef F
    bool solve() {
        scc.solve();
        var.clear();
        for (int i = 0; i < n; i++) if (scc.grp[i] == scc.grp[i + n]) return false;
        var.resize(n);
        for (int i = 0; i < n; i++) var[i] = (scc.grp[i] > scc.grp[i + n]);
        return true;
    }
}; // }}}

const int N=1010;

int n,c[N];
string s[N][2];

int main() {
    R(n);
    REP(i,n) {
        string a,b;
        R(a,b);
        s[i][0]=a.substr(0,3);
        s[i][1]=a.substr(0,2)+b[0];
    }
    TwoSAT sat;
    sat.init(n);
    REP(i,n) REP(j,n) if ( i!=j ) REP(x,2) REP(y,2) if ( s[i][x]==s[j][y] ) {
        sat.imply(i,x,j,y^1);
        if ( x==0 && y==0 ) sat.imply(i,1,j,1);
    }
    if ( sat.solve() ) {
        W("YES");
        REP(i,n) W(s[i][sat.var[i]]);
    } else {
        W("NO");
    }
    return 0;
}