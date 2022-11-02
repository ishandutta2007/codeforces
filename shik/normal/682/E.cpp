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

const int N=5010;

struct P {
    LL x,y;
} p[3*N];

bool operator <( const P &a, const P &b ) { return tie(a.x,a.y)<tie(b.x,b.y); }
P operator +( const P &a, const P &b ) { return {a.x+b.x,a.y+b.y}; }
P operator -( const P &a, const P &b ) { return {a.x-b.x,a.y-b.y}; }
LL operator *( const P &a, const P &b ) { return a.x*b.y-b.x*a.y; }
LL X( const P &o, const P &a, const P &b ) { return (a-o)*(b-o); }
LL X( int o, int a, int b ) { return X(p[o],p[a],p[b]); }

int n;
LL s;

void convex_hull() {
    static P q1[N],q2[N];
    int m1=0,m2=0;
    sort(p,p+n);
    REP(i,n) {
        while ( m1>=2 && X(q1[m1-2],q1[m1-1],p[i])<=0 ) m1--;
        while ( m2>=2 && X(q2[m2-2],q2[m2-1],p[i])>=0 ) m2--;
        q1[m1++]=q2[m2++]=p[i];
    }
    n=0;
    REP(i,m1) p[n++]=q1[i];
    for ( int i=m2-2; i>0; i-- ) p[n++]=q2[i];
}

tuple<int,int,int> max_tri() {
    REP(i,n) p[i+n+n]=p[i+n]=p[i];
    LL mx=-1;
    int a=-1,b=-1,c=-1;
    for ( int i=0,j=1,k=2; i<n; i++ ) {
        while ( X(i,j,k+1)>X(i,j,k) ) k++;
        while ( X(i,j+1,k)>X(i,j,k) ) j++;
        LL now=X(i,j,k);
        if ( now>mx ) {
            mx=now;
            tie(a,b,c)=tie(i,j,k);
        }
        if ( j>=n ) j-=n;
        if ( k>=n ) k-=n;
    }
    return make_tuple(a,b,c);
}

int main() {
    R(n,s); s*=2;
    REP(i,n) R(p[i].x,p[i].y);
    convex_hull();
    int a,b,c;
    tie(a,b,c)=max_tri();
    assert(X(a,b,c)<=s);
    P pa=p[a]+p[c]-p[b];
    P pb=p[b]+p[a]-p[c];
    P pc=p[c]+p[b]-p[a];
    assert(X(pa,pb,pc)<=4*s);
    W(pa.x,pa.y);
    W(pb.x,pb.y);
    W(pc.x,pc.y);
    return 0;
}