// {{{ by shik
// #include <stdio.h>
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

struct SAM {
    struct nd { int l, p; array<int, 26> e; };
    vector<nd> v;
    SAM() : v(2, nd{0, 0, {{0}}}) {}
    void push(int c) {
        int wh = v.size(), st = wh - 1, it = st;
        while (it && !v[it].e[c]) it = v[it].p;
        if (it && v[v[it].e[c]].l != v[it].l + 1) {
            int cp = wh++, ob = v[it].e[c];
            v.push_back(nd{v[it].l + 1, v[ob].p, v[ob].e});
            for (v[ob].p = cp; it && v[it].e[c] == ob; it = v[it].p) v[it].e[c] = cp;
        }
        for (it = st; it && !v[it].e[c]; it = v[it].p) v[it].e[c] = wh;
        v.push_back(nd{v[st].l + 1, it ? v[it].e[c] : 1, v[0].e});
    }
};

const int N=1e5+10;

int n;
char s[N];
void solve() {
    R(s);
    n=strlen(s);
    SAM sam;
    REP(i,n) sam.push(s[i]-'a');
    int x=1,m=SZ(sam.v);
    VI ord(m),r(m);
    REP(i,n) {
        x=sam.v[x].e[s[i]-'a'];
        r[x]++;
    }
    REP(i,SZ(ord)) ord[i]=i;
    sort(ALL(ord),[&]( int a, int b ) { return sam.v[a].l<sam.v[b].l; });
    for ( int ii=SZ(ord)-1; ii>=1; ii-- ) {
        int i=ord[ii];
        r[sam.v[i].p]+=r[i];
    }
    LL ans=0;
    REP1(i,2,SZ(sam.v)-1) {
        LL lb=sam.v[sam.v[i].p].l+1;
        LL rb=sam.v[i].l;
        LL now=(rb-lb+1)*r[i]*r[i];
        // dump(i,lb,rb,r[i]);
        ans+=now;
    }
    W(ans);
}

int main() {
    int t;
    R(t);
    while ( t-- ) {
        solve();
    }
    return 0;
}