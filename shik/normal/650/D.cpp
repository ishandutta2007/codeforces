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

const int N=400010;
const int INF=1e9+10;
int n,m,h[N],qa[N],qb[N],isl[N],isr[N],dpl[N],dpr[N],was[N],cnt[N],ans[N];
bool uniq[N];
VI vq[N];
int main() {
    R(n,m); 
    REP1(i,1,n) R(h[i]);
    REP(i,m) R(qa[i],qb[i]);

    REP(i,n) isl[i]=INF+i;
    REP1(i,1,n) {
        int x=h[i];
        int j=lower_bound(isl,isl+n,x)-isl;
        dpl[i]=j;
        isl[j]=x;
    }

    REP(i,n) isr[i]=INF+i;
    for ( int i=n; i>=1; i-- ) {
        int x=1000000000-h[i]+1;
        int j=lower_bound(isr,isr+n,x)-isr;
        dpr[i]=j;
        was[i]=isr[j];
        isr[j]=x;
    }

    int lis_len=0;
    while ( lis_len<n && isl[lis_len]<INF ) lis_len++;

    REP1(i,1,n) if ( dpl[i]+dpr[i]+1==lis_len ) cnt[dpl[i]]++;
    REP1(i,1,n) if ( dpl[i]+dpr[i]+1==lis_len && cnt[dpl[i]]==1 ) uniq[i]=1;

    REP(i,n) isl[i]=INF+i;
    REP(i,m) vq[qa[i]].PB(i);
    REP1(i,1,n) {
        isr[dpr[i]]=was[i];
        for ( int j:vq[i] ) {
            int x=qb[j];
            int l=lower_bound(isl,isl+n,x)-isl;
            int r=lower_bound(isr,isr+n,1000000000-x+1)-isr;
            ans[j]=l+r+1;
            if ( uniq[i] ) ans[j]=max(ans[j],lis_len-1);
            else ans[j]=max(ans[j],lis_len);
        }
        isl[dpl[i]]=h[i];
    }
    REP(i,m) W(ans[i]);
    return 0;
}