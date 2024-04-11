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

VI factor( int x ) {
    VI f;
    for ( int i=2; i*i<=x; i++ ) if ( x%i==0 ) {
        f.PB(i);
        while ( x%i==0 ) x/=i;
    }
    if ( x>1 ) f.PB(x);
    return f;
}

int n,x,y,a[N];

int t[N];
LL solve( int g ) {
    REP1(i,1,n) {
        if ( a[i]%g==0 ) t[i]=0;
        else if ( (a[i]-1)%g==0 || (a[i]+1)%g==0 ) t[i]=1;
        else t[i]=2;
    }
    int l=0,r=0;
    REP1(i,1,n) {
        if ( !l && t[i]==2 ) l=i;
        if ( t[i]==2 ) r=i;
    }
    dump(l,r);
    if ( !l ) {
        LL ans=0;
        REP1(i,1,n) if ( t[i] ) ans+=y;
        LL s=0,mx=0;
        REP1(i,1,n) {
            if ( t[i] ) s+=y;
            s-=x;
            if ( s<0 ) s=0;
            mx=max(mx,s);
        }
        ans-=mx;
        return ans;
    } else {
        LL ans=0;
        REP1(i,1,n) {
            if ( l<=i && i<=r ) ans+=x;
            else if ( t[i] ) ans+=y;
        }
        LL sl=0,mxl=0;
        for ( int i=l-1; i>=0; i-- ) {
            if ( t[i] ) sl+=y;
            sl-=x;
            mxl=max(mxl,sl);
        }
        LL sr=0,mxr=0;
        REP1(i,r+1,n) {
            if ( t[i] ) sr+=y;
            sr-=x;
            mxr=max(mxr,sr);
        }
        ans-=mxl;
        ans-=mxr;
        return ans;
    }
}

int main() {
    R(n,x,y);
    REP1(i,1,n) R(a[i]);
    VI f;
    for ( int i:{1,n} ) REP1(j,-1,+1) {
        VI v=factor(a[i]+j);
        f.insert(f.end(),ALL(v));
    }
    sort(ALL(f));
    f.erase(unique(ALL(f)),f.end());
    LL ans=1e18;
    for ( int i:f ) {
        LL now=solve(i);
        dump(i,now);
        ans=min(ans,now);
    }
    W(ans);
    return 0;
}