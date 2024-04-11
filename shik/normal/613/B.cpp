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

const int N=1e5+10;

int n;
LL A,cf,cm,m,sa[N],sol[N];
pair<LL,int> a[N];

LL chk( int mid, LL t ) {
    LL s=sa[mid];
    LL z=a[mid].first*mid;
    return t-(z-s);
}

LL shik( int r, LL t ) {
    if ( r==0 ) return A;
    int l=1;
    while ( l!=r ) {
        int mid=(l+r+1)/2;
        if ( chk(mid,t)>=0 ) l=mid;
        else r=mid-1;
    }
    LL tt=chk(l,t);
    assert(tt>=0);
    return min(A,a[l].first+tt/l);
}

int main() {
    R(n,A,cf,cm,m);
    REP1(i,1,n) R(a[i].first);
    REP1(i,1,n) a[i].second=i;
    sort(a+1,a+n+1);
    REP1(i,1,n) sa[i]=sa[i-1]+a[i].first;
    LL ans=-1,s=0,ws=-1;
    int wi=-1;
    REP1(i,0,n) {
        LL x=shik(n-i,m-s);
        LL now=i*cf+x*cm;
        dump(i,x,now);
        if ( now>ans ) tie(ans,wi,ws)=tie(now,i,s);
        s+=A-a[n-i].first;
        if ( s>m ) break;
    }
    REP(i,wi) a[n-i].first=A;
    LL x=shik(n-wi,m-ws);
    REP1(i,1,n) if ( a[i].first<x ) a[i].first=x;
    REP1(i,1,n) sol[a[i].second]=a[i].first;
    W(ans);
    W(vector<LL>(sol+1,sol+n+1));
    LL mi=sol[1];
    REP1(i,1,n) mi=min(mi,sol[i]);
    int cnt=0;
    REP1(i,1,n) if ( sol[i]==A ) cnt++;
    LL now=cnt*cf+mi*cm;
    dump(cnt,mi,now,ans);
    assert(now==ans);
    return 0;
}