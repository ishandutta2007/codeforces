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

const int N=1e5+10;

pair<double,double> f( double p1, double q1, double p2, double q2 ) {
    double p3=p2==0?0:p1*p2/(1-(1-p2)*(1-q1));
    double q3=q1==0?0:q1*q2/(1-(1-q1)*(1-p2));
    return {p3,q3};
}

struct Seg {
    double p[4*N],q[4*N];
    void pull( int id ) {
        double p1=p[id*2],q1=q[id*2];
        double p2=p[id*2+1],q2=q[id*2+1];
        tie(p[id],q[id])=f(p1,q1,p2,q2);
    }
    void init( int id, int l, int r, double *a ) {
        if ( l==r ) {
            p[id]=a[l];
            q[id]=1-a[l];
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m,a);
        init(id*2+1,m+1,r,a);
        pull(id);
    }
    void chg( int id, int l, int r, int qx, double qp ) {
        if ( l==r ) {
            p[id]=qp;
            q[id]=1-qp;
            return;
        }
        int m=(l+r)/2;
        if ( qx<=m ) chg(id*2,l,m,qx,qp);
        else chg(id*2+1,m+1,r,qx,qp);
        pull(id);
    }
    pair<double,double> ask( int id, int l, int r, int ql, int qr ) {
        if ( ql<=l && r<=qr ) return {p[id],q[id]};
        int m=(l+r)/2;
        if ( qr<=m ) return ask(id*2,l,m,ql,qr);
        else if ( ql>m ) return ask(id*2+1,m+1,r,ql,qr);
        else {
            auto al=ask(id*2,l,m,ql,qr);
            auto ar=ask(id*2+1,m+1,r,ql,qr);
            return f(al.first,al.second,ar.first,ar.second);
        }
    }
} seg;

int n,m;
double p[N];
int main() {
    R(n,m);
    REP1(i,1,n) {
        int a,b;
        R(a,b);
        p[i]=1.0*a/b;
    }
    seg.init(1,1,n,p);
    while ( m-- ) {
        int op;
        R(op);
        if ( op==1 ) {
            int x,a,b;
            R(x,a,b);
            seg.chg(1,1,n,x,1.0*a/b);
        } else if ( op==2 ) {
            int l,r;
            R(l,r);
            auto ans=seg.ask(1,1,n,l,r);
            printf("%.14f\n",ans.first);
        } else assert(0);
    }
    return 0;
}