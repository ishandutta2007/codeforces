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

const int N=1e6+10;
bitset<N> p_tbl;
vector<int> primes;
void sieve() {
    p_tbl[1]=1;
    for ( int i=2; i<N; i++ ) {
        if ( !p_tbl[i] ) primes.push_back(i);
        for ( int p:primes ) {
            int x=i*p;
            if ( x>=N ) break;
            p_tbl[x]=1;
            if ( i%p==0 ) break;
        }
    }
}

const LL MOD=1e9+7;

LL f( LL n ) {
    LL u=sqrt(n);
    while ( u*u<=n ) u++;
    LL ans=n;
    for ( int i:primes ) {
        if ( n%i==0 ) {
            ans=ans/i*(i-1);
            n/=i;
            while ( n%i==0 ) n/=i;
        }
        if ( i>u ) break;
    }
    if ( n!=1 ) {
        ans=ans/n*(n-1);
        n/=n;
    }
    return ans;
}

int f2( int n ) {
    if ( n==1 ) return 1;
    int c=0;
    REP1(i,1,n-1) if ( __gcd(i,n-i)==1 ) c++;
    return c;
}


LL F( LL n, LL k ) {
    if ( k==1 ) return f(n);
    if ( k%2==0 ) return F(n,k-1);
    if ( k%2==1 ) return f(F(n,k-1));
    assert(0);
}

int main() {
    sieve();
    REP1(i,1,1000) assert(f(i)==f2(i));
    LL n,k;
    R(n,k);
    k=min(k,217LL);
    LL ans=F(n,k);
    ans%=MOD;
    W(ans);
    return 0;
}