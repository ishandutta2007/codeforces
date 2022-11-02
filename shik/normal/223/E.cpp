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

struct E {
    int to,flow;
    long double ang;
};

#ifdef SHIK
ostream& operator<<( ostream &o, const E &e ) {
    return o<<MP(e.to,MP(e.flow,e.ang));
}
#endif

bool operator <( const E &a, const E &b ) {
    return a.ang<b.ang;
}

int n,m;
LL x[N],y[N];
vector<E> e[N];
vector<int> sf[N];

inline long double get_ang( int a, int b ) {
    map<PII,long double> memo;
    auto k=MP(a,b);
    if ( memo.count(k) ) return memo[k];
    else return memo[k]=atan2l(y[b]-y[a],x[b]-x[a]);
}

double cross( int a, int b ) {
    return x[a]*y[b]-x[b]*y[a];
}

bool vis[N];
int dfs( int p ) {
    vis[p]=1;
    int s=1;
    for ( auto &i:e[p] ) if ( !vis[i.to] ) {
        int f=dfs(i.to);
        i.flow=-f;
        for ( auto &j:e[i.to] ) if ( j.to==p ) j.flow=f;
        s+=f;
    }
    return s;
}

int main() {
    R(n,m);
    REP(i,m) {
        int a,b;
        R(a,b);
        e[a].PB({b,0,0});
        e[b].PB({a,0,0});
    }
    REP1(i,1,n) R(x[i],y[i]);
    int w=1;
    REP1(i,1,n) if ( x[i]<x[w] ) w=i;
    x[0]=x[w]-1;
    e[0].PB({w,0,0});
    e[w].PB({0,0,0});
    dfs(0);
    REP1(i,0,n) {
        for ( auto &j:e[i] ) j.ang=get_ang(i,j.to);
        sort(ALL(e[i]));
        sf[i].PB(0);
        for ( auto &j:e[i] ) sf[i].PB(sf[i].back()+j.flow);
        dump(i,e[i],sf[i]);
    }
    int q;
    R(q);
    while ( q-- ) {
        static int np,p[N];
        R(np);
        REP(i,np) R(p[i]);
        p[np]=p[0];

        double area=0;
        REP(i,np) area+=cross(p[i],p[i+1]);
        if ( area<0 ) reverse(p,p+np+1);
        p[np+1]=p[1];

        int ans=0;
        REP(ii,np) {
            int i=p[ii],j=p[ii+1],k=p[ii+2];
            auto aji=get_ang(j,i);
            auto ajk=get_ang(j,k);
            int ti=lower_bound(ALL(e[j]),E{0,0,aji})-e[j].begin();
            int tk=lower_bound(ALL(e[j]),E{0,0,ajk})-e[j].begin();
            assert(ti<SZ(e[j]) && e[j][ti].to==i);
            assert(tk<SZ(e[j]) && e[j][tk].to==k);
            dump(i,j,k,ti,tk,aji,ajk);
            if ( ti<tk ) {
                ans+=sf[j][tk]-sf[j][ti+1];
            } else {
                ans+=sf[j].back()-sf[j][ti+1];
                ans+=sf[j][tk];
            }
        }
        W(ans);
    }
    return 0;
}