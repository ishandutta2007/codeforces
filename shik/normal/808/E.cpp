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

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int M=3e5+10;
const int K=100;
int n,m;
VI v[4];

int main() {
    R(n,m);
    REP(i,n) {
        int w,c;
        R(w,c);
        v[w].PB(c);
    }
    REP1(i,1,3) sort(ALL(v[i]));
    LL base=0;
    while ( m>=K && SZ(v[1])>=6 && SZ(v[2])>=3 && SZ(v[3])>=2 ) {
        LL tc[4]={};
        REP1(i,1,3) REP(j,6/i) tc[i]+=v[i][SZ(v[i])-j-1];
        if ( tc[1]>=tc[2] && tc[1]>=tc[3] ) {
            base+=v[1].back();
            v[1].pop_back();
            m--;
        } else if ( tc[2]>=tc[1] && tc[2]>=tc[3] ) {
            base+=v[2].back();
            v[2].pop_back();
            m-=2;
        } else {
            base+=v[3].back();
            v[3].pop_back();
            m-=3;
        }
    }
    if ( m<K ) {
        static LL dp[K];
        REP1(i,1,3) for ( int j:v[i] ) for ( int k=m; k>=i; k-- ) chkmax(dp[k],dp[k-i]+j);
        LL ans=base+dp[m];
        W(ans);
    } else {
        REP1(i,1,3) {
            v[i].PB(0);
            reverse(ALL(v[i]));
            REP1(j,1,SZ(v[i])-1) v[i][j]+=v[i][j-1];
        }
        int o[3]={1,2,3};
        sort(o,o+3,[&]( int x, int y ) { return SZ(v[x])<SZ(v[y]); });
        LL mx=0;
        REP(i,SZ(v[o[0]])) {
            REP(j,SZ(v[o[1]])) {
                int rem=m-o[0]*i-o[1]*j;
                if ( rem>=0 ) {
                    int k=min(SZ(v[o[2]])-1,rem/o[2]);
                    chkmax(mx,0LL+v[o[0]][i]+v[o[1]][j]+v[o[2]][k]);
                }
            }
        }
        LL ans=base+mx;
        W(ans);
    }
    return 0;
}