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

const int N=5e5+10;
const int M=1e7+10;
const int MOD=1e9+7;

void fix( LL &x ) {
    x%=MOD;
    if ( x<0 ) x+=MOD;
}

int mu[M],p_tbl[M];
vector<int> primes;
void sieve() {
    mu[1]=p_tbl[1]=1;
    for ( int i=2; i<M; i++ ) {
        if ( !p_tbl[i] ) {
            p_tbl[i]=i;
            primes.push_back(i);
            mu[i]=-1;
        }
        for ( int p:primes ) {
            int x=i*p;
            if ( x>=M ) break;
            p_tbl[x]=p;
            mu[x]=-mu[i];
            if ( i%p==0 ) {
                mu[x]=0;
                break;
            }
        }
    }
}

LL p2[N];
void predo() {
    sieve();
    p2[0]=1;
    REP1(i,1,N-1) p2[i]=p2[i-1]*2%MOD;
}

VI factor( int x ) {
    VI fac{1};
    while ( x>1 ) {
        int fn=SZ(fac),p=p_tbl[x],pos=0;
        while ( x%p==0 ) {
            x/=p;
            REP(i,fn) fac.PB(fac[pos++]*p);
        }
    }
    return fac;
}

int n,a[N],cnt[M],memo_sc[M];

int shik( int x ) {
    LL ans=0;
    auto fac=factor(x);
    for ( auto f:fac ) {
        if ( mu[f]==0 ) continue;
        int sc=memo_sc[f];
        assert(sc>=1);
        LL ori=mu[f]*(p2[sc]-1);
        LL now=mu[f]*(p2[sc-1]-1);
        ans+=ori-now;
    }
    fix(ans);
    return ans;
}

int main() {
    predo();
    RI(n);
    REP(i,n) RI(a[i]);
    sort(a,a+n);
    REP(i,n) cnt[a[i]]++;
    LL g1=0;
    REP1(i,1,M-1) if ( mu[i]!=0 ) {
        int sc=0;
        for ( int j=i; j<M; j+=i ) sc+=cnt[j];
        if ( sc==0 ) continue;
        memo_sc[i]=sc;
        g1+=mu[i]*(p2[sc]-1);
    }
    fix(g1);
    LL ans=0;
    REP1(i,2,M-1) if ( cnt[i] ) {
        LL g2=g1-shik(i);
        ans+=cnt[i]*(g1-2*g2)%MOD;
    }
    fix(ans);
    cout<<ans<<endl;
    return 0;
}