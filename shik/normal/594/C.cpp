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

const int N=1e5+10;
int n,m,a[N][4],x[N],y[N];
set<PII> sx,sy;

void del( int id ) {
    sx.erase(MP(x[id],id));
    sy.erase(MP(y[id],id));
}

void ins( int id ) {
    sx.insert(MP(x[id],id));
    sy.insert(MP(y[id],id));
}

LL get_area() {
    LL l=sx.begin()->first;
    LL d=sy.begin()->first;
    LL r=sx.rbegin()->first;
    LL u=sy.rbegin()->first;
    LL w=(r-l+1)/2;
    if ( w==0 ) w=1;
    LL h=(u-d+1)/2;
    if ( h==0 ) h=1;
    return w*h;
}

LL ans=1e18;
void dfs( int pos, int rem ) {
    dump(pos,rem);
    if ( pos==4 ) {
        LL now=get_area();
        ans=min(ans,now);
        return;
    }
    int id;
    if ( pos==0 ) id=sx.begin()->second;
    else if ( pos==1 ) id=sy.begin()->second;
    else if ( pos==2 ) id=sx.rbegin()->second;
    else if ( pos==3 ) id=sy.rbegin()->second;
    else assert(0);
    dump(id);
    if ( rem>0 ) {
        del(id);
        dfs(pos,rem-1);
        ins(id);
    }
    dfs(pos+1,rem);
    
}

int main() {
    R(n,m);
    REP(i,n) REP(j,4) R(a[i][j]);
    REP(i,n) {
        x[i]=a[i][0]+a[i][2];
        y[i]=a[i][1]+a[i][3];
    }
    REP(i,n) ins(i);
    dfs(0,m);
    W(ans);
    return 0;
}