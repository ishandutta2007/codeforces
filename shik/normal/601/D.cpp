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

const int N=3e5+10;
const LL MOD=1000000000000037;
const int H=131;

struct BIT {
    int dat[N];
    void ins( int x, int v ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
} bit;

int n,c[N];
char ch[N];
VI e[N];

LL h[N];
int l[N],r[N],ts;
void dfs( int p, LL sh ) {
    l[p]=++ts;
    h[ts]=sh;
    for ( int i:e[p] ) {
        e[i].erase(find(ALL(e[i]),p));
        dfs(i,(sh*H+ch[i])%MOD);
    }
    r[p]=ts;
}

int main() {
    R(n);
    REP1(i,1,n) R(c[i]);
    scanf("%s",ch+1);
    REP(i,n-1) {
        int a,b;
        R(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    dfs(1,ch[1]);
    static VI vq[N];
    REP1(i,1,n) vq[l[i]].PB(i);
    static int dif[N];
    map<LL,int> last;
    for ( int i=n; i>=1; i-- ) {
        if ( last.count(h[i]) ) bit.ins(last[h[i]],-1);
        last[h[i]]=i;
        bit.ins(i,+1);
        for ( int j:vq[i] ) dif[j]=bit.ask(r[j]);
    }
    int mx=0;
    REP1(i,1,n) mx=max(mx,dif[i]+c[i]);
    int cnt=0;
    REP1(i,1,n) if ( dif[i]+c[i]==mx ) cnt++;
    W(mx);
    W(cnt);
    return 0;
}