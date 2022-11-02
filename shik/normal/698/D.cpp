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

const int N=7;
const int M=1010;

struct P {
    LL x,y;
    LL len2() { return x*x+y*y; }
};

P operator -( const P &a, const P &b ) { return {a.x-b.x,a.y-b.y}; }
LL operator *( const P &a, const P &b ) { return a.x*b.y-b.x*a.y; }
LL X( const P &o, const P &a, const P &b ) { return (a-o)*(b-o); }
LL dis2( const P &a, const P &b ) { return (a-b).len2(); }
bool line( const P &a, const P &b, const P &c ) {
    if ( b.x<min(a.x,c.x) || b.x>max(a.x,c.x) ) return 0;
    if ( b.y<min(a.y,c.y) || b.y>max(a.y,c.y) ) return 0;
    return X(a,b,c)==0;
}


int n,m,ord[M],vis[M],vid;
LL d2[M];
bool can[M];
VI to[N][M];
P a[N],b[M];

bool cmp_d2( int x, int y ) {
    return d2[x]<d2[y];
}

int main() {
    R(n,m);
    REP(i,n) R(a[i].x,a[i].y);
    REP(i,m) R(b[i].x,b[i].y);
    REP(i,m) ord[i]=i;
    REP(i,n) {
        REP(j,m) d2[j]=dis2(a[i],b[j]);
        sort(ord,ord+m,cmp_d2);
        REP(jj,m) {
            int j=ord[jj];
            auto &v=to[i][j];
            REP1(kk,0,jj) {
                int k=ord[kk];
                if ( line(a[i],b[k],b[j]) ) v.PB(k);
                if ( SZ(v)>=n ) break;
            }
        }
    }
    REP(i,n) REP(j,m) dump(i,j,to[i][j]);
    int per[N];
    REP(i,n) per[i]=i;
    do {
        REP(i,m) if ( !can[i] ) {
            vid++;
            VI stk;
            stk.reserve(16);
            vis[i]=vid;
            stk.PB(i);
            REP(jj,n) {
                if ( SZ(stk)>n-jj ) break;
                int j=per[jj];
                int g=stk.back();
                stk.pop_back();
                for ( int k:to[j][g] ) {
                    if ( vis[k]==vid ) continue;
                    vis[k]=vid;
                    stk.PB(k);
                }
                if ( stk.empty() ) {
                    can[i]=1;
                    break;
                }
            }
        }
    } while ( next_permutation(per,per+n) );
    dump(vector<bool>(can,can+m));
    int ans=0;
    REP(i,m) if ( can[i] ) ans++;
    W(ans);
    return 0;
}