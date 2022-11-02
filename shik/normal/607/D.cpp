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

// }}}

#if 0
#define ZZ(...) __VA_ARGS__
#else
#define ZZ(...)
#endif

const int N=2e5+10;
const int B=500;
const int MOD=1e9+7;

LL inv[N];
void predo() {
    inv[1]=1;
    REP1(i,2,N-1) inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
}

struct Q {
    int op,x;
} q[N];

int n,v[N],p[N],qn;
void input() {
    R(v[1],qn);
    ZZ(v[1]=rand()%1000000000; qn=200000;)
    n=1;
    REP(i,qn) {
        int op;
        R(op);
        ZZ(op=(i==qn-1?2:1);)
        if ( op==1 ) {
            n++;
            R(p[n],v[n]);
            ZZ(p[n]=n-1; v[n]=rand()%1000000000;)
            q[i]={1,n};
        } else if ( op==2 ) {
            q[i].op=2;
            R(q[i].x);
            ZZ(q[i].x=1;)
        } else assert(0);
    }
    dump(n,VI(p+1,p+n+1),VI(v+1,v+n+1));
}

bool care[N];
int sz[N],pp[N];
LL pw[N],dp[N];
            
void upd( int u, LL x ) {
    while ( u ) {
        dump(u,pw[u],x);
        pw[u]+=x;
        if ( pw[u]>=MOD ) pw[u]-=MOD;
        x=x*dp[u]%MOD;
        u=pp[u];
        x=x*sz[u]%MOD;
    }
}

int tn=1;
void solve( int l, int r ) {
    memset(care+1,0,n*sizeof(bool));
    care[1]=1;
    REP1(i,l,r) {
        int x=q[i].x;
        if ( q[i].op==1 ) care[p[x]]=1,tn++;
        else care[x]=1;
    }
    REP1(i,2,tn) {
        if ( care[p[i]] ) {
            pp[i]=p[i];
            dp[i]=1;
        } else {
            pp[i]=pp[p[i]];
            dp[i]=dp[p[i]]*sz[p[i]]%MOD;
        }
    }
    dump(VI(pp+1,pp+n+1));
    dump(VI(dp+1,dp+n+1));
    REP1(i,l,r) {
        int x=q[i].x;
        if ( q[i].op==1 ) {
            pw[x]=v[x];
            sz[x]=1;
            int f=p[x];
            LL sd=(pw[f]*inv[sz[f]]+v[x])%MOD;
            sz[f]++;
            LL add=(sd*sz[f]-pw[f]+MOD)%MOD;
            dump(f,add);
            upd(f,add);
        } else {
            W(pw[x]);
        }
    }
    REP1(i,1,tn) pw[i]=0;
    for ( int i=tn; i>=1; i-- ) {
        pw[i]=(pw[i]+v[i])%MOD*sz[i]%MOD;
        pw[p[i]]+=pw[i];
    }
    dump(VI(pw+1,pw+n+1));
}

int main() {
    predo();
    input();
    pw[1]=v[1];
    sz[1]=1;
    for ( int i=0; i<qn; i+=B ) {
        int l=i,r=min(qn,i+B)-1;
        solve(l,r);
    }
    return 0;
}