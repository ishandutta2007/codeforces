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
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

const int MOD=1e9+7;
const int L=2e5+10;
const int N=2014;

LL inv[L],fac[L],ifac[L];
void predo() {
    inv[1]=1;
    REP1(i,2,L-1) inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    fac[0]=1;
    REP1(i,1,L-1) fac[i]=fac[i-1]*i%MOD;
    ifac[0]=1;
    REP1(i,1,L-1) ifac[i]=ifac[i-1]*inv[i]%MOD;
}

LL C( int n, int m ) {
    return fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}

struct P {
    int x,y;
} p[N];

bool operator <( const P &a, const P &b ) {
    return tie(a.x,a.y)<tie(b.x,b.y);
}

LL dp[N][2];
int main() {
    predo();
    int h,w,n;
    RI(h,w,n);
    REP(i,n) RI(p[i].x,p[i].y);
    p[n++]=P{1,1};
    p[n++]=P{h,w};
    sort(p,p+n);
    dp[0][0]=1;
    REP(i,n) {
        LL *me=dp[i];
        me[0]%=MOD;
        me[1]%=MOD;
        REP1(j,i+1,n-1) if ( p[i].x<=p[j].x && p[i].y<=p[j].y ) {
            int dx=p[j].x-p[i].x;
            int dy=p[j].y-p[i].y;
            LL c=C(dx+dy,dx);
            dp[j][0]+=me[1]*c%MOD;
            dp[j][1]+=me[0]*c%MOD;
        }
    }
    LL ans=dp[n-1][1]-dp[n-1][0];
    ans%=MOD;
    if ( ans<0 ) ans+=MOD;
    cout<<ans<<endl;
    return 0;
}