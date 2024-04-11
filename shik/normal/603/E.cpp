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
const int M=3e5+10;

struct DJS {
    int sz[N],fa[N],c_odd;
    vector<pair<int*,int>> h;
    vector<int> sp;
    void init( int n ) {
        REP1(i,1,n) {
            fa[i]=i;
            sz[i]=1;
        }
        c_odd=n;
    }
    void z( int *k, int v ) {
        h.PB({k,*k});
        *k=v;
    }
    void save() {
        sp.PB(SZ(h));
    }
    void undo() {
        assert(!sp.empty());
        int last=sp.back();
        sp.pop_back();
        while ( SZ(h)!=last ) {
            auto &x=h.back();
            *x.first=x.second;
            h.pop_back();
        }
    }
    int f( int x ) {
        while ( fa[x]!=x ) x=fa[x];
        return x;
    }
    void u( int a, int b ) {
        dump(a,b);
        a=f(a);
        b=f(b);
        if ( a==b ) return;
        if ( sz[a]>sz[b] ) swap(a,b);
        z(&c_odd,c_odd-(sz[a]%2)-(sz[b]%2)+((sz[a]+sz[b])%2));
        z(&sz[b],sz[a]+sz[b]);
        z(&fa[a],b);
    }
} djs;

int n,m,a[M],b[M],c[M],sc[M],sol[M];

void go( int l1, int r1, int l2, int r2 ) {
    if ( l1>r1 || l2>r2 ) return;

    dump(l1,r1,l2,r2);

    if ( c[sc[l2]]==c[sc[r2]] ) {
        djs.save();
        int cc=c[sc[l2]];
        REP1(ii,l2,r2) {
            int i=sc[ii];
            if ( i<l1 ) djs.u(a[i],b[i]);
        }
        REP1(i,l1,r1) {
            if ( c[i]<=cc ) djs.u(a[i],b[i]);
            if ( djs.c_odd==0 ) sol[i]=cc;
            else sol[i]=-1;
            dump(i,a[i],b[i],c[i],djs.c_odd);
        }
        djs.undo();
        return;
    }

    int m2=(l2+r2)/2;
    while ( m2<r2 && c[sc[m2+1]]==c[sc[m2]] ) m2++;
    if ( m2==r2 ) {
        m2=(l2+r2)/2;
        while ( m2>l2 && c[sc[m2-1]]==c[sc[m2]] ) m2--;
        assert(m2!=l2);
        m2--;
    }
    int mc=c[sc[m2]];

    dump(m2,mc);
    
    djs.save();
    REP1(ii,l2,m2) {
        int i=sc[ii];
        if ( i<l1 ) djs.u(a[i],b[i]);
    }

    int m1=l1;
    djs.save();
    while ( m1<=r1 ) {
        if ( c[m1]<=mc ) {
            djs.u(a[m1],b[m1]);
            if ( djs.c_odd==0 ) break;
        }
        m1++;
    }
    djs.undo();

    dump(m1);

    go(l1,m1-1,m2+1,r2);
    djs.undo();

    djs.save();
    int lc=c[sc[l2]];
    REP1(i,l1,m1-1) if ( c[i]<lc ) {
        djs.u(a[i],b[i]);
    }
    go(m1,r1,l2,m2);
    djs.undo();

}

bool cmp( int x, int y ) {
    return c[x]<c[y];
}

int main() {
    R(n,m);
    REP1(i,1,m) R(a[i],b[i],c[i]);
    REP1(i,1,m) sc[i]=i;
    sort(sc+1,sc+m+1,cmp);
    djs.init(n);
    go(1,m,1,m);
    REP1(i,1,m) W(sol[i]);
    return 0;
}