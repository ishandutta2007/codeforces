// {{{ by shik
#pragma GCC optimize("O3")
#pragma GCC target("avx")
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
void _debug( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _debug( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _debug(s+1,tail...);
}

#define debug(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _debug(#__VA_ARGS__, __VA_ARGS__); \
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
#define debug(...)
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

typedef vector<int> V;

const int Q=1e5+10;
const int N=1010;
typedef bitset<N> B;
B b[Q+N];
V v[Q];
int nb=1,num[Q];

int main() {
    int n,m,q;
    R(n,m,q);
    v[0]=V(n+1,0);
    REP1(qi,1,q) {
        int op;
        R(op);
        V &vv=v[qi];
        int &nn=num[qi];
        if ( op!=4 ) {
            vv=v[qi-1];
            nn=num[qi-1];
        }
        if ( op==1 ) {
            int x,y;
            R(x,y);
            if ( !(b[vv[0]][x]^b[vv[x]][y]) ) {
                b[nb]=b[vv[x]];
                b[vv[x]=nb++].flip(y);
                nn++;
            }
        } else if ( op==2 ) {
            int x,y;
            R(x,y);
            if ( b[vv[0]][x]^b[vv[x]][y] ) {
                b[nb]=b[vv[x]];
                b[vv[x]=nb++].flip(y);
                nn--;
            }
        } else if ( op==3 ) {
            int x;
            R(x);
            b[nb]=b[vv[0]];
            b[vv[0]=nb++].flip(x);
            int t=b[vv[x]].count();
            if ( b[vv[0]][x] ) nn+=m-t-t;
            else nn+=t+t-m;
        } else if ( op==4 ) {
            int x;
            R(x);
            vv=v[x];
            nn=num[x];
        } else assert(0);
        W(nn);
    }
    return 0;
}