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

typedef pair<LL,LL> PLL;
inline bool cmp( const PLL &a, const PLL &b ) {
    // a.first/a.second > b.first/b.second
    return a.first*b.second > b.first*a.second;
}

inline bool eq( const PLL &a, const PLL &b ) {
    // a.first/a.second > b.first/b.second
    return a.first*b.second == b.first*a.second;
}

int n,l[N],r[N],op[N];
LL p[N],t[N],st[N];

bool cmp_p( int a, int b ) {
    return p[a]<p[b];
}

double mi[N],mx[N];
const double eps=0;
bool chk( double c ) {
    double T=st[n];
    REP(i,n) {
        mx[i]=p[i]*(1.0-c*(st[l[i]]+t[i])/T);
        mi[i]=p[i]*(1.0-c*st[r[i]+1]/T);
    }
    double big=-1;
    for ( int i=0,j; i<n; i=j ) {
        double nb=-1;
        for ( j=i; j<n && p[op[i]]==p[op[j]]; j++ ) {
            if ( mi[op[j]]+eps<big ) return 0;
            nb=max(nb,mx[op[j]]);
        }
        big=max(big,nb);
    }
    return 1;
}

int main() {
    R(n);
    REP(i,n) R(p[i]);
    REP(i,n) R(t[i]);
    vector<PLL> v;
    REP(i,n) v.PB(MP(p[i],t[i]));
    stable_sort(ALL(v),cmp);
    REP(i,n) tie(p[i],t[i])=v[i];
    REP(i,n) {
        if ( i==0 || !eq(v[i],v[i-1]) ) l[i]=i;
        else l[i]=l[i-1];
    }
    for ( int i=n-1; i>=0; i-- ) {
        if ( i==n-1 || !eq(v[i],v[i+1]) ) r[i]=i;
        else r[i]=r[i+1];
    }
    REP(i,n) op[i]=i;
    sort(op,op+n,cmp_p);
    st[0]=0;
    REP(i,n) st[i+1]=st[i]+t[i];
    double lc=0,rc=1;
    REP(i,60) {
        double mc=(lc+rc)/2;
        if ( chk(mc) ) lc=mc;
        else rc=mc;
    }
    printf("%.14f\n",(lc+rc)/2);
    return 0;
}