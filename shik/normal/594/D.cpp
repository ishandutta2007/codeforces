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
} while (0);

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

// }}}

const int S=1e6+10;
int p_tbl[S];
vector<int> primes;
void sieve() {
    p_tbl[1]=1;
    for ( int i=2; i<S; i++ ) {
        if ( !p_tbl[i] ) {
            primes.push_back(i);
            p_tbl[i]=i;
        }
        for ( int p:primes ) {
            int x=i*p;
            if ( x>=S ) break;
            p_tbl[x]=p;
            if ( i%p==0 ) break;
        }
    }
}

VI factor( int x ) {
    VI f;
    while ( x>1 ) {
        int p=p_tbl[x];
        f.PB(p);
        while ( x%p==0 ) x/=p;
    }
    return f;
}

const int MOD=1e9+7;

int inv[S],tbl[S],lbt[S];
void predo() {
    inv[1]=1;
    REP1(i,2,S-1) inv[i]=1LL*inv[MOD%i]*(MOD-MOD/i)%MOD;
    REP1(i,2,S-1) if ( p_tbl[i]==i ) {
        tbl[i]=(i-1LL)*inv[i]%MOD;
        lbt[i]=1LL*inv[i-1]*i%MOD;
    }
}

const int N=2e5+10;

struct BIT {
    LL dat[N];
    void init() {
        REP(i,N) dat[i]=1;
    }
    void ins( int x, int v ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]=dat[i]*v%MOD;
    }
    int ask( int x ) {
        LL s=1;
        for ( int i=x; i; i-=i&-i ) s=s*dat[i]%MOD;
        return s;
    }
} bit;

struct Q {
    int l,r;
} q[N];

int n,a[N],m,last[S],sol[N];
VI vq[N];
int main() {
    sieve();
    predo();
    R(n);
    REP1(i,1,n) R(a[i]);
    R(m);
    REP(i,m) R(q[i].l,q[i].r);
    REP(i,m) vq[q[i].l].PB(i);
    bit.init();
    for ( int i=n; i>=1; i-- ) {
        bit.ins(i,a[i]);
        VI f=factor(a[i]);
        for ( int p:f ) {
            bit.ins(i,tbl[p]);
            if ( last[p] ) bit.ins(last[p],lbt[p]);
            last[p]=i;
        }
        for ( int qid:vq[i] ) {
            int r=q[qid].r;
            int ans=bit.ask(r);
            sol[qid]=ans;
        }
    }
    REP(i,m) W(sol[i]);
    return 0;
}