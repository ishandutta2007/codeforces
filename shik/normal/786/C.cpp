// {{{ by shik
// #pragma GCC optimize("O3")
// #include <stdio.h>
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
void _W( const long long &x ) { printf("%" PRId64,x); }
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

struct SplitMix32 {
    uint32_t s;
    SplitMix32(uint32_t _s = 0) : s(_s) {}
    uint32_t operator()() {
        uint32_t z = (s += 0x9e3779b1);
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
} rnd;

const int N=1e5+10;
const int T=500;
const int M=217;

struct C {
    int c[N],m;
    VI v;
    void clear() {
        m=0;
        for ( int i:v ) c[i]=0;
        v.clear();
    }
    void ins( int x ) {
        if ( c[x]++==0 ) m++;
        v.PB(x);
    }
    void del( int x ) {
        if ( --c[x]==0 ) m--;
    }
};

struct P {
    int l,r;
    C c;
    void clear( int a[] ) {
        REP1(i,l,r) c.c[a[i]]=0;
        c.m=0;
    }
} p[M];

int n,a[N],sol[N];

int naive( int k ) {
    static C c;
    int ans=1;
    REP1(i,1,n) {
        c.ins(a[i]);
        if ( c.m>k ) {
            c.clear();
            ans++;
            c.ins(a[i]);
        }
    }
    c.clear();
    return ans;
}

int main() {
    R(n);
    REP1(i,1,n) R(a[i]);
    int t=min(n,T);
    REP1(i,1,t) sol[i]=naive(i);
    if ( t+1<=n ) {
        int m=1;
        p[0].l=1;
        REP1(i,1,n) {
            p[m-1].c.ins(a[i]);
            if ( p[m-1].c.m>t+1 ) {
                p[m-1].c.del(a[i]);
                p[m-1].r=i-1;
                m++;
                p[m-1].l=i;
                p[m-1].c.ins(a[i]);
            }
        }
        p[m-1].r=n;
        assert(m<M);
        sol[t+1]=m;
        REP1(i,t+2,n) {
            REP(j,m) {
                if ( j>0 ) {
                    if ( p[j-1].r>=p[j].r ) {
                        p[j].clear(a);
                        p[j].l=p[j-1].r+1;
                        p[j].r=p[j].l;
                        p[j].c.ins(a[p[j].r]);
                    } else {
                        while ( p[j].l<=p[j-1].r ) {
                            p[j].c.del(a[p[j].l]);
                            p[j].l++;
                        }
                    }
                }
                while ( p[j].r<n && p[j].c.m<=i ) {
                    p[j].r++;
                    p[j].c.ins(a[p[j].r]);
                }
                if ( p[j].c.m>i ) {
                    p[j].c.del(a[p[j].r]);
                    p[j].r--;
                }
                if ( p[j].r==n ) {
                    m=j+1;
                    break;
                }
            }
            sol[i]=m;
        }
    }
    REP1(i,1,n) printf("%d%c",sol[i],i==n?'\n':' ');
    return 0;
}