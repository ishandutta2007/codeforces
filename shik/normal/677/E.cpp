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

const int N=1010;
const LL MOD=1e9+7;
const long double l2=logl(2.0L);
const long double l3=logl(3.0L);

int n,a[N][N],sa[N][N][2][4],dp[N][N][8];

PII get_plus( int x, int y, int d ) {
    int c2=0,c3=0;
    c2+=sa[x][y+d-1][0][0]-sa[x][y-d][0][0];
    c3+=sa[x][y+d-1][1][0]-sa[x][y-d][1][0];
    c2+=sa[x+d-1][y][0][2]-sa[x-d][y][0][2];
    c3+=sa[x+d-1][y][1][2]-sa[x-d][y][1][2];
    if ( a[x][y]==2 ) c2--;
    if ( a[x][y]==3 ) c3--;
    return {c2,c3};
}

PII get_croxx( int x, int y, int d ) {
    int c2=0,c3=0;
    c2+=sa[x+d-1][y+d-1][0][1]-sa[x-d][y-d][0][1];
    c3+=sa[x+d-1][y+d-1][1][1]-sa[x-d][y-d][1][1];
    c2+=sa[x+d-1][y-d+1][0][3]-sa[x-d][y+d][0][3];
    c3+=sa[x+d-1][y-d+1][1][3]-sa[x-d][y+d][1][3];
    if ( a[x][y]==2 ) c2--;
    if ( a[x][y]==3 ) c3--;
    return {c2,c3};
}

int main() {
    R(n);
    REP1(i,1,n) {
        char buf[N];
        R(buf);
        REP1(j,1,n) a[i][j]=buf[j-1]-'0';
    }
    REP1(i,1,n) REP1(j,1,n) REP(k,2) {
        sa[i][j][k][0]=sa[i  ][j-1][k][0]+(a[i][j]==k+2);
        sa[i][j][k][1]=sa[i-1][j-1][k][1]+(a[i][j]==k+2);
        sa[i][j][k][2]=sa[i-1][j  ][k][2]+(a[i][j]==k+2);
        sa[i][j][k][3]=sa[i-1][j+1][k][3]+(a[i][j]==k+2);
    }
    REP1(i,1,n) REP1(j,1,n) if ( a[i][j]!=0 ) {
        dp[i][j][0]=dp[i  ][j-1][0]+1;
        dp[i][j][1]=dp[i-1][j-1][1]+1;
        dp[i][j][2]=dp[i-1][j  ][2]+1;
        dp[i][j][3]=dp[i-1][j+1][3]+1;
    }
    for ( int i=n; i>=1; i-- ) for ( int j=n; j>=1; j-- ) if ( a[i][j]!=0 ) {
        dp[i][j][4]=dp[i  ][j+1][4]+1;
        dp[i][j][5]=dp[i+1][j-1][5]+1;
        dp[i][j][6]=dp[i+1][j  ][6]+1;
        dp[i][j][7]=dp[i+1][j+1][7]+1;
    }
    PII ans{0,0};
    long double mx=0;
    auto upd=[&]( PII p ) {
        auto x=p.first*l2+p.second*l3;
        if ( x>mx ) {
            mx=x;
            ans=p;
        }
    };
    bool all_zero=1;
    REP1(i,1,n) REP1(j,1,n) if ( a[i][j]!=0 ) {
        all_zero=0;
        int *me=dp[i][j];
        int d1=min(min(me[0],me[2]),min(me[4],me[6]));
        auto p1=get_plus(i,j,d1);
        upd(p1);
        int d2=min(min(me[1],me[3]),min(me[5],me[7]));
        auto p2=get_croxx(i,j,d2);
        upd(p2);
    }
    if ( all_zero ) W(0);
    else {
        LL v=1;
        REP(i,ans.first) v=v*2%MOD;
        REP(i,ans.second) v=v*3%MOD;
        W(v);
    }
	return 0;
}