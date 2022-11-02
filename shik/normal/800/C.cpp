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

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int M=2e5+10;

LL inv(LL x, LL m) {
    LL a = x, b = m, u = 1, v = 0;
    while (b != 0) {
        LL t = a / b;
        a -= t * b;
        u -= t * v;
        swap(a, b);
        swap(u, v);
    }
    u = ((u % m) + m) % m;
    return u;
}

int n,m,dp[M],frm[M];
bool ban[M];
VI v[M];
int main() {
    R(n,m);
    REP(i,n) {
        int x;
        R(x);
        ban[x]=1;
    }
    REP(i,m) if ( !ban[i] ) v[__gcd(i,m)].PB(i);
    dp[m]=SZ(v[m]);
    frm[m]=-1;
    for ( int i=m-1; i>=1; i-- ) if ( m%i==0 ) {
        int mx=-1,wh=-1;
        for ( int j=i+i; j<=m; j+=i ) if ( m%j==0 && dp[j]>mx ) tie(mx,wh)=tie(dp[j],j);
        assert(wh!=-1);
        dp[i]=mx+SZ(v[i]);
        frm[i]=wh;
    }
    VI path;
    {
        int x=1;
        while ( x!=-1 ) {
            for ( int i:v[x] ) path.PB(i);
            x=frm[x];
        }
    }
    assert(SZ(path)==dp[1]);
    VI sol;
    sol.PB(path[0]);
    REP1(i,1,SZ(path)-1) {
        int x=path[i-1];
        int y=path[i];
        int g=__gcd(x,m);
        assert(y%g==0);
        int t=1LL*inv(x/g,m/g)*(y/g)%m;
        sol.PB(t);
    }
    LL x=1;
    for ( int i:sol ) {
        x=x*i%m;
        assert(!ban[x]);
        ban[x]=1;
    }
    W(SZ(sol));
    W(sol);
    return 0;
}