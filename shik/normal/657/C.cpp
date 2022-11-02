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
const int OFF=1e9;

int n,m,b,c;
LL a[N];
int main() {
    R(n,m,b,c);
    REP(i,n) R(a[i]);
    b=min(b,5*c);
    sort(a,a+n);
    REP(i,n) a[i]+=OFF;
    vector<LL> cand[5];
    REP1(i,m-1,n-1) REP(j,5) cand[(a[i]+j)%5].PB(a[i]+j);
    REP(i,5) {
        auto &v=cand[i];
        sort(ALL(v));
        v.erase(unique(ALL(v)),v.end());
    }
    LL ans=9e18;
    REP(ci,5) {
        int idx=0,tot=0;
        LL cr[5]={},sq[5]={};
        queue<int> qq[5];
        for ( LL x:cand[ci] ) {
            while ( idx<n && a[idx]<=x ) {
                LL q=a[idx]/5;
                int r=a[idx]%5;
                sq[r]+=q;
                qq[r].push(q);
                cr[r]++;
                tot++;
                idx++;
            }
            LL q=x/5;
            int r=x%5;
            while ( tot>m ) {
                LL mx=-1,who=-1;
                REP(i,5) if ( !qq[i].empty() ) {
                    LL now=0;
                    if ( i<=r ) {
                        now+=b*(q-qq[i].front());
                        now+=c*(r-i);
                    } else {
                        now+=b*(q-1-qq[i].front());
                        now+=c*(r+5-i);
                    }
                    if ( now>mx ) mx=now,who=i;
                }
                assert(who!=-1);
                assert(!qq[who].empty());
                sq[who]-=qq[who].front();
                qq[who].pop();
                cr[who]--;
                tot--;
            }
            LL now=0;
            REP(i,5) {
                if ( i<=r ) {
                    now+=b*(cr[i]*q-sq[i]);
                    now+=c*cr[i]*(r-i);
                } else {
                    now+=b*(cr[i]*(q-1)-sq[i]);
                    now+=c*cr[i]*(r+5-i);
                }
            }
            dump(x,now);
            ans=min(ans,now);
        }
    }
    W(ans);
    return 0;
}