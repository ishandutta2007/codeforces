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

const LL MOD=1e9+7;

struct M {
    LL a[2][2];
    LL* operator[]( int i ) {
        return a[i];
    }
    const LL* operator[]( int i ) const {
        return a[i];
    }
};

const M A{{{0,1},{1,1}}};
const M I{{{1,0},{0,1}}};
const M Z{{{0,0},{0,0}}};

M operator +( const M &a, const M &b ) {
    M c;
    REP(i,2) REP(j,2) {
        c[i][j]=a[i][j]+b[i][j];
        if ( c[i][j]>=MOD ) c[i][j]-=MOD;
    }
    return c;
}

M operator *( const M &a, const M &b ) {
    M c=Z;
    REP(i,2) REP(j,2) {
        REP(k,2) c[i][j]+=a[i][k]*b[k][j];
        c[i][j]%=MOD;
    }
    return c;
}

M operator ^( const M &a, int b ) {
    M s=I,r=a;
    while ( b ) {
        if ( b&1 ) s=s*r;
        r=r*r;
        b>>=1;
    }
    return s;
}

const int N=1e5+10;

struct Seg {
    M sum[4*N],mul[4*N];

    M get_sum( int id ) {
        return sum[id]*mul[id];
    }
    
    void push( int id ) {
        mul[id*2]=mul[id*2]*mul[id];
        mul[id*2+1]=mul[id*2+1]*mul[id];
        mul[id]=I;
    }

    void pull( int id ) {
        sum[id]=get_sum(id*2)+get_sum(id*2+1);
    }

    void init( int id, int l, int r, int a[] ) {
        mul[id]=I;
        if ( l==r ) {
            sum[id]=A^a[l];
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m,a);
        init(id*2+1,m+1,r,a);
        pull(id);
    }

    void ins( int id, int l, int r, int ql, int qr, const M &qx ) {
        if ( ql<=l && r<=qr ) {
            mul[id]=mul[id]*qx;
            return;
        }
        push(id);
        int m=(l+r)/2;
        if ( ql<=m ) ins(id*2,l,m,ql,qr,qx);
        if ( qr>m ) ins(id*2+1,m+1,r,ql,qr,qx);
        pull(id);
    }

    M ask( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return get_sum(id);
        push(id);
        M s=Z;
        int m=(l+r)/2;
        if ( ql<=m ) s=s+ask(id*2,l,m,ql,qr);
        if ( qr>m ) s=s+ask(id*2+1,m+1,r,ql,qr);
        pull(id);
        return s;
    }
} seg;

int n,m,a[N];
int main() {
    R(n,m);
    REP1(i,1,n) R(a[i]);
    seg.init(1,1,n,a);
    while ( m-- ) {
        int op;
        R(op);
        if ( op==1 ) {
            int l,r,x;
            R(l,r,x);
            M qx=A^x;
            seg.ins(1,1,n,l,r,qx);
        } else if ( op==2 ) {
            int l,r;
            R(l,r);
            M t=seg.ask(1,1,n,l,r);
            LL ans=t[0][1];
            W(ans);
        } else assert(0);
        // dump(m);
        // REP1(i,1,n) dump(i,seg.ask(1,1,n,i,i)[0][1]);
    }
    return 0;
}