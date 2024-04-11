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

const int N=1e6+10;
vector<int> primes;
int mu[N],smu[N],p_tbl[N];
void sieve() {
    mu[1]=p_tbl[1]=1;
    for ( int i=2; i<N; i++ ) {
        if ( !p_tbl[i] ) {
            primes.push_back(i);
            p_tbl[i]=i;
            mu[i]=-1;
        }
        for ( int p:primes ) {
            int x=i*p;
            if ( x>=N ) break;
            p_tbl[x]=p;
            mu[x]=-mu[i];
            if ( i%p==0 ) {
                mu[x]=0;
                break;
            }
        }
    }
    for ( int i=1; i<N; i++ ) for ( int j=1; i*j<N; j++ ) smu[i*j]+=i*mu[j];
}

vector<int> factor( int x ) {
    static map<int,VI> memo;
    if ( memo.count(x) ) return memo[x];
    int x_bak=x;
    vector<int> fac{1};
    while ( x>1 ) {
        int fn=fac.size(),p=p_tbl[x],pos=0;
        while ( x%p==0 ) {
            x/=p;
            for ( int i=0; i<fn; i++ ) fac.push_back(fac[pos++]*p);
        }
    }
    memo[x_bak]=fac;
    return fac;
}

const int MOD=1e9+7;
LL inv[N],fac[N],ifac[N];
void predo() {
    inv[1]=1;
    REP1(i,2,N-1) inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    fac[0]=1;
    REP1(i,1,N-1) fac[i]=fac[i-1]*i%MOD;
    ifac[0]=1;
    REP1(i,1,N-1) ifac[i]=ifac[i-1]*inv[i]%MOD;
}

inline LL C( int n, int m ) {
    if ( n<m ) return 0;
    return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}

int n,k,q,w[N];
inline LL g( int i ) {
    return smu[i]*C(w[i],k)%MOD;
}

int main() {
    sieve();
    predo();
    R(n,k,q);
    LL ans=0;
    REP(i,n+q) {
        int x;
        R(x);
        auto f=factor(x);
        for ( int j:f ) {
            ans-=g(j);
            w[j]++;
            ans+=g(j);
        }
        dump(i,x,f,ans);
        ans%=MOD;
        if ( ans<0 ) ans+=MOD;
        if ( i>=n ) W(ans);
    }
    return 0;
}