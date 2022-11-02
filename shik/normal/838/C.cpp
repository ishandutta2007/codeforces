// {{{ by shik
#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("O3,no-stack-protector")
#pragma GCC target("tune=native")
// #include <stdio.h>
#endif
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
// }}}}}}

LL inv( LL x, LL p ) {
    LL a = x, b = p, u = 1, v = 0;
    while (b != 0) {
        auto t = a / b;
        a -= t * b;
        u -= t * v;
        swap(a, b);
        swap(u, v);
    }
    return u < 0 ? u + p : u;
}

inline int bit( LL x, int i ) {
    return (x>>i)&1;
}

const int K=26;
const int N=250010;
LL p;

int rev[N],tbl[N],tbl2[N/2];
int dp[2][N/2];
// const LL G=8e18;
LL n,k;

int main() {
    R(n,k,p);
    LL ans=1;
    REP(i,n) ans=ans*k%p;
    if ( n%2==0 ) {
        LL up=1;
        REP1(i,1,n) up=up*i%p;
        rev[0]=rev[1]=1;
        REP1(i,2,n) rev[i]=(LL)rev[p%i]*(p-p/i)%p;
        tbl[0]=1;
        REP1(i,1,n) tbl[i]=(LL)tbl[i-1]*rev[i]%p;
        REP1(i,0,n/2) tbl2[i]=tbl[i*2];
        n/=2;
        int u=0;
        dp[u][0]=1;
        for ( int i=n; i; i=(i-1)&n ) dp[u][i]=tbl2[i];
        const LL G=LLONG_MAX-p*p;
        const LL pp=G/p*p;
        REP(ik,k-1) {
            u^=1;
            memset(dp[u],0,n*sizeof(int));
            dp[u][0]=1;
            // for ( int i=n; i; i=(i-1)&n ) {
            for ( int i=1; i<=n; i++ ) if ( (n&i)==i ) {
                LL s=dp[u^1][i];
                for ( int j=i; j; j=(j-1)&i ) {
                    s+=(LL)tbl2[j]*dp[u^1][i^j];
                    // if ( s>G ) s-=pp;
                    if ( s>G ) s%=p;
                    // if ( s>G ) s=fmodl(s,p);
                }
                dp[u][i]=s%p;
            }
        }
        LL dn=dp[u][n];
        LL t=up*dn%p;
        dump(up,dn,t);
        ans=(ans-t%p+p)%p;
    }
    W(ans);
    return 0;
}