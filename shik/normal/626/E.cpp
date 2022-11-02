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
typedef long double Double;

int n,a[N];
LL sa[N];

Double mean( int l1, int r1, int l2, int r2 ) {
    LL s=sa[r1]-sa[l1-1]+sa[r2]-sa[l2-1];
    int c=r1-l1+1+r2-l2+1;
    return Double(s)/c;
}

int main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    if ( n<=2 ) {
        W(1);
        W(a[1]);
        return 0;
    }
    sort(a+1,a+n+1);
    REP1(i,1,n) sa[i]=sa[i-1]+a[i];
    Double ans=0;
    VI sol{1,1,2,2};
    REP1(i,2,n-1) {
        int l=1,r=min(i-1,n-i);
        while ( l!=r ) {
            int m1=(l+l+r)/3;
            int m2=(l+r+r+2)/3;
            auto x1=mean(i-m1,i,n-m1+1,n);
            auto x2=mean(i-m2,i,n-m2+1,n);
            if ( x1<x2 ) l=m1+1;
            else r=m2-1;
        }
        auto x=mean(i-l,i,n-l+1,n)-a[i];
        if ( x>ans ) {
            ans=x;
            sol={i-l,i,n-l+1,n};
        }
    }
    REP1(i,3,n-1) {
        int l=1,r=min(i-2,n-i);
        while ( l!=r ) {
            int m1=(l+l+r)/3;
            int m2=(l+r+r+2)/3;
            auto x1=mean(i-m1-1,i,n-m1+1,n);
            auto x2=mean(i-m2-1,i,n-m2+1,n);
            if ( x1<x2 ) l=m1+1;
            else r=m2-1;
        }
        auto x=mean(i-l-1,i,n-l+1,n)-(a[i]+a[i-1])/2.0l;
        if ( x>ans ) {
            ans=x;
            sol={i-l-1,i,n-l+1,n};
        }
    }
    VI v;
    assert(SZ(sol)==4);
    REP1(i,sol[0],sol[1]) v.PB(a[i]);
    REP1(i,sol[2],sol[3]) v.PB(a[i]);
    W(SZ(v));
    W(v);
    return 0;
}