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

typedef long double Double;

const int N=3e5+10;
const Double dpi=acos(-1)/180;

struct P {
    Double a,d;
    Double x() { return d*cos(a); }
    Double y() { return d*sin(a); }
};

ostream& operator <<( ostream &s, const P &p ) { return s<<"("<<p.a<<","<<p.d<<")"; }

P merge( P a, P b, Double &da ) {
    b.a+=a.a;
    Double x=a.x()+b.x();
    Double y=a.y()+b.y();
    Double ang=atan2(y,x);
    Double dis=sqrt(x*x+y*y);
    da=b.a-ang;
    // dump(a.x(),a.y(),b.x(),b.y(),ang,dis,da);
    return {ang,dis};
}

struct Q {
    int op,id,x;
};

ostream& operator <<( ostream &s, const Q &q ) { return s<<"("<<q.op<<","<<q.id<<","<<q.x<<")"; }

void reduce( vector<P> &ps, vector<Q> &qs ) {
    static bool vis[N];
    static int mp[N];
    int np=SZ(ps);
    REP(i,np) vis[i]=0;
    for ( auto &q:qs ) {
        assert(q.id<SZ(ps));
        vis[q.id]=1;
    }
    VI ids;
    vector<P> nps;
    Double da=0;
    REP(i,np) {
        ps[i].a+=da;
        if ( i==0 || vis[i-1] || vis[i] ) {
            nps.PB(ps[i]);
            ids.PB(i);
            da=0;
        } else {
            nps.back()=merge(nps.back(),ps[i],da);
        }
    }
    ps=nps;
    int nid=SZ(ids);
    REP(i,nid) mp[ids[i]]=i;
    for ( auto &q:qs ) q.id=mp[q.id];
}

void apply( vector<P> &ps, Q &q ) {
    assert(q.id<SZ(ps));
    if ( q.op==1 ) ps[q.id].d+=q.x;
    else ps[q.id].a-=q.x*dpi;
}

void go( vector<P> ps, vector<Q> qs ) {
    // dump(ps,qs);
    reduce(ps,qs);
    // dump(ps,qs);
    if ( SZ(qs)==1 ) {
        apply(ps,qs[0]);
        // dump(ps);
        Double da=0;
        auto p=ps[0];
        REP1(i,1,SZ(ps)-1) {
            ps[i].a+=da;
            p=merge(p,ps[i],da);
            // dump(i,p);
        }
        printf("%.14f %.14f\n",(double)p.x(),(double)p.y());
        return;
    }
    int mid=SZ(qs)/2;
    vector<Q> ql(qs.begin(),qs.begin()+mid);
    go(ps,ql);
    for ( auto &q:ql ) apply(ps,q);
    vector<Q> qr(qs.begin()+mid,qs.end());
    go(ps,qr);
}

int main() {
    int n,m;
    R(n,m);
    vector<P> ps;
    REP(i,n) ps.PB({0,1});
    vector<Q> qs(m);
    REP(i,m) {
        R(qs[i].op,qs[i].id,qs[i].x);
        qs[i].id--;
    }
    go(ps,qs);
    return 0;
}