// {{{ by shik
#pragma GCC optimize("O3")
#pragma GCC target("avx")
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

inline char next_char() {
    static char buf[1<<16];
    static char *p = buf, *end = buf;
    if ( p==end ) {
        end=buf+fread(buf,1,sizeof(buf),stdin);
        p=buf;
    }
    return *p++;
}

inline int gn() {
    int c;
    while ( (c=next_char())<'0' || c>'9' );
    int x=c-'0';
    while ( (c=next_char())>='0' && c<='9' ) x=x*10+c-'0';
    return x;
}

const int N=2010;
const int K=2010;
const int QN=1e6+10;

struct BIT {
    LL dat[N][N];
    void ins( int x, int y, int z ) {
        // dump(x,y,z);
        for ( int i=x; i<N; i+=i&-i )
            for ( int j=y; j<N; j+=j&-j )
                dat[i][j]+=z;
    }
    LL ask( int x, int y ) {
        LL s=0;
        for ( int i=x; i; i-=i&-i )
            for ( int j=y; j; j-=j&-j )
                s+=dat[i][j];
        // dump(x,y,s);
        return s;
    }
    LL ask( int x1, int y1, int x2, int y2 ) {
        LL s=0;
        s+=ask(x2,y2);
        s-=ask(x1-1,y2);
        s-=ask(x2,y1-1);
        s+=ask(x1-1,y1-1);
        return s;
    }
} bit;

struct P {
    int len,x[N],y[N],z[N];
    void read() {
		len=gn();
        REP(i,len) {
            x[i]=gn();
            y[i]=gn();
            z[i]=gn();
        }
    }
} p[K];

struct Q {
    int op,x1,y1,x2,y2;
    void read() {
        char ch=next_char();
        if ( ch=='S' ) {
            op=0;
            x1=gn();
        } else if ( ch=='A' ) {
            op=1;
            x1=gn();
            y1=gn();
            x2=gn();
            y2=gn();
        } else assert(0);
    }
} q[QN];

int n,m,k,qn;
LL t[N][N];
bool on[N];

int main() {
    n=gn();
    m=gn();
    k=gn();
    REP1(i,1,k) p[i].read();
    qn=gn();
    REP(i,qn) q[i].read();
    dump("XD");
    VI v;
    REP(i,qn) if ( q[i].op==1 ) v.PB(i);
    REP1(i,1,k) {
        REP(j,p[i].len) bit.ins(p[i].x[j],p[i].y[j],+p[i].z[j]);
        REP(j,SZ(v)) {
            auto &qq=q[v[j]];
            t[i][j]=bit.ask(qq.x1,qq.y1,qq.x2,qq.y2);
            // dump(i,j,t[i][j]);
        }
        REP(j,p[i].len) bit.ins(p[i].x[j],p[i].y[j],-p[i].z[j]);
    }
    REP1(i,1,k) on[i]=1;
    int qc=0;
    REP(i,qn) {
        if ( q[i].op==0 ) {
            on[q[i].x1]^=1;
        } else if ( q[i].op==1 ) {
            LL ans=0;
            REP1(j,1,k) if ( on[j] ) ans+=t[j][qc];
            qc++;
            W(ans);
        } else assert(0);
    }
    return 0;
}