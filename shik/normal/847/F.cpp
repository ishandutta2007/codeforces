// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

template<class T> void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }
void R() {}
template<class T, class... U> void R( T& head, U&... tail ) { _R(head); R(tail...); }

template<class T> void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
void _W( const int64_t &x ) { printf("%" PRId64,x); }
void _W( const double &x ) { printf("%.16f\n",x); }
void _W( const char &x ) { putchar(x); }
void _W( const char *x ) { printf("%s",x); }
template<class T> void _W( const vector<T> &x ) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W( const T& head, const U&... tail ) { _W(head); putchar(sizeof...(tail)?' ':'\n'); W(tail...); }

template<class T> inline bool chkmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chkmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

#ifdef SHIK
template<class T> void _dump(const char *s, T &&head) { cerr << s << "=" << head << endl; }
template<class T, class... Args> void _dump(const char *s, T &&head, Args &&... tail) {
    for (int c = 0; *s != ',' || c != 0; cerr << *s++) {
        if (*s == '(' || *s == '[' || *s == '{') c++;
        if (*s == ')' || *s == ']' || *s == '}') c--;
    }
    cerr << "=" << head << ", ";
    _dump(s + 1, tail...);
}
#define dump(...) do { fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); _dump(#__VA_ARGS__, __VA_ARGS__); } while (0)

template<class Iter> ostream &_out(ostream &s, Iter b, Iter e) {
    s << "[";
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    return s << "]";
}

template<class A, class B> ostream &operator<<(ostream &s, const pair<A, B> &p) { return s << "(" << p.first << "," << p.second << ")"; }
template<class T> ostream &operator<<(ostream &s, const vector<T> &c) { return _out(s, ALL(c)); }
template<class T, size_t N> ostream &operator<<(ostream &s, const array<T, N> &c) { return _out(s, ALL(c)); }
template<class T> ostream &operator<<(ostream &s, const set<T> &c) { return _out(s, ALL(c)); }
template<class A, class B> ostream &operator<<(ostream &s, const map<A, B> &c) { return _out(s, ALL(c)); }
#else
#define dump(...)
#endif
// }}}

const int N=110;
const int M=110;
int n,k,m,a,g[M],c[N],last[N],f[N];

bool cmp( int x, int y ) {
    if ( c[x]!=c[y] ) return c[x]>c[y];
    return last[x]<last[y];
}

int main() {
    R(n,k,m,a);
    REP1(i,1,a) R(g[i]);
    REP1(i,1,a) {
        c[g[i]]++;
        last[g[i]]=i;
    }
    REP1(i,1,n) {
        if ( c[i]==0 && a==m ) continue;
        int t=c[i]+(m-a),z=0;
        REP1(j,1,n) if ( i!=j && (c[j]>t || (c[j]==t && (a<m || (a==m && last[j]<last[i])))) ) z++;
        if ( z<k ) f[i]|=1;
    }
    REP1(i,1,n) {
        if ( c[i]==0 ) {
            f[i]|=2;
            continue;
        }
        VI v;
        REP1(j,1,n) if ( i!=j ) v.PB(j);
        if ( SZ(v)<k ) continue;
        sort(ALL(v),cmp);
        int z=0;
        REP(jj,k) {
            int j=v[jj];
            if ( c[j]>0 && cmp(j,i) ) continue;
            z+=c[i]-c[j]+1;
        }
        if ( z<=m-a ) f[i]|=2;
    }
    VI r;
    REP1(i,1,n) {
        dump(i,f[i]);
        if ( f[i]==1 ) r.PB(1);
        if ( f[i]==2 ) r.PB(3);
        if ( f[i]==3 ) r.PB(2);
    }
    W(r);
    return 0;
}