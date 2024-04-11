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

const int N=2e5+10;
const int MOD=1e9+7;

int n,par[N];
VI e[N];

int dp1[N];
int go1( int p ) {
    LL s=1;
    for ( int i:e[p] ) {
        s=s*(1+go1(i))%MOD;
    }
    return dp1[p]=s;
}

int dp2[N];
void go2( int p ) {
    vector<LL> v{dp2[p]};
    for ( int i:e[p] ) v.PB(v.back()*(1+dp1[i])%MOD);
    LL s=1;
    for ( int i=SZ(e[p])-1; i>=0; i-- ) {
        int to=e[p][i];
        v.pop_back();
        dp2[to]=(1+v.back()*s)%MOD;
        s=s*(1+dp1[to])%MOD;
    }
    for ( int i:e[p] ) go2(i);
}

int main() {
    RI(n);
    REP1(i,2,n) RI(par[i]);
    REP1(i,2,n) e[par[i]].PB(i);
    go1(1);
    dp2[1]=1;
    go2(1);
    dump(VI(dp1+1,dp1+n+1));
    dump(VI(dp2+1,dp2+n+1));
    REP1(i,1,n) {
        int ans=1LL*dp1[i]*dp2[i]%MOD;
        printf("%d%c",ans," \n"[i==n]);
    }
    return 0;
}