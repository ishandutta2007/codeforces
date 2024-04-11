// {{{ by shik
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

template<typename T> inline bool chkmax(T &a, const T &b) { return b > a ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, true : false; }

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int N=2e5+10;
const LL INF=1e18;

struct Q {
    LL sq1;
    priority_queue<int> q1;
    priority_queue<int,VI,greater<int>> q2;
    void push( int x ) {
        if ( q2.empty() || x<=q2.top() ) {
            sq1+=x;
            q1.push(x);
        } else {
            q2.push(x);
        }
    }
    LL get( int m ) {
        if ( m>SZ(q1)+SZ(q2) ) return INF;
        assert(0<=m);
        assert(SZ(q1)+SZ(q2)>=m);
        while ( SZ(q1)<m ) {
            int x=q2.top(); q2.pop();
            sq1+=x;
            q1.push(x);
        }
        while ( SZ(q1)>m ) {
            int x=q1.top(); q1.pop();
            sq1-=x;
            q2.push(x);
        }
        return sq1;
    }
} q;

int n,m,k,c[N],d[N],l1,l2;
VI v[4];

LL solve() {
    LL ans=INF;
    int i3=0;
    chkmax(i3,k-SZ(v[1]));
    chkmax(i3,k-SZ(v[2]));
    if ( i3>SZ(v[3]) ) return -1;
    int i2=k-i3;
    int i1=k-i3;
    // dump(i1,i2,i3);
    LL now=0;
    REP(i,i1) now+=v[1][i];
    REP(i,i2) now+=v[2][i];
    REP(i,i3) now+=v[3][i];
    for ( int i:v[0] ) q.push(i);
    REP1(i,i1,SZ(v[1])-1) q.push(v[1][i]);
    REP1(i,i2,SZ(v[2])-1) q.push(v[2][i]);
    while ( 1 ) {
        int i0=m-i1-i2-i3;
        // dump(i0,i1,i2,i3);
        if ( i0>=0 ) {
            LL w=now+q.get(i0);
            chkmin(ans,w);
        }

        if ( i3==SZ(v[3]) ) break;

        now+=v[3][i3];
        i3++;

        if ( i1>0 ) {
            now-=v[1][--i1];
            q.push(v[1][i1]);
        }

        if ( i2>0 ) {
            now-=v[2][--i2];
            q.push(v[2][i2]);
        }
    }
    return ans>=INF ? -1 : ans;
}

int main() {
    R(n,m,k);
    if ( k>m ) {
        W(-1);
        return 0;
    }
    REP1(i,1,n) R(c[i]);
    R(l1);
    REP(i,l1) {
        int x;
        R(x);
        d[x]|=1;
    }
    R(l2);
    REP(i,l2) {
        int x;
        R(x);
        d[x]|=2;
    }
    REP1(i,1,n) v[d[i]].PB(c[i]);
    REP(i,4) sort(ALL(v[i]));
    // dump(v[0],v[1],v[2],v[3]);
    LL ans=solve();
    W(ans);
    return 0;
}