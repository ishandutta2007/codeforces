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

inline int bit( int x, int i ) { return (x>>i)&1; }

const int N=3e5+10;
const int INF=1e9;

int n,a[N],s[N],dp[N][4];

int slow() {
    int ans=INF;
    REP(i,1<<n) {
        int now=0,b=0;
        REP(j,n) {
            if ( bit(i,j) ) {
                now+=a[j];
                b+=a[j]/10;
            } else {
                int t=min(a[j],b);
                now+=a[j]-t;
                b-=t;
            }
        }
        chkmin(ans,now);
    }
    return ans;
}

int solve1() {
    REP1(i,1,n) REP(j,4) dp[i][j]=INF;
    REP(i,n) REP(j,4) {
        int me=dp[i][j];
        int bit=(a[i]/1000);
        int b=me/1000*100-(s[i]-me);
        int c=max(a[i]-b,0);
        // dump(i,j,me,b,c);
        if ( j&bit ) {
            chkmin(dp[i+1][j],me+a[i]);
            chkmin(dp[i+1][j^bit],me+c);
        } else {
            chkmin(dp[i+1][j],me+c);
        }
    }
    int ans=*min_element(ALL(dp[n]));
    return ans;
}

int f( int c1, int c2 ) {
    int now=0,b=0;
    REP(i,n) {
        if ( a[i]==1000 ) {
            if ( c1>0 ) {
                now+=1000;
                b+=100;
                c1--;
            } else {
                int t=min(a[i],b);
                now+=a[i]-t;
                b-=t;
            }
        } else {
            if ( c2>0 ) {
                now+=2000;
                b+=200;
                c2--;
            } else {
                int t=min(a[i],b);
                now+=a[i]-t;
                b-=t;
            }
        }
    }
    // dump(c1,c2,now);
    return now;
}

int solve2() {
    int sum=0,tot=0;
    REP(i,n) tot+=a[i];
    int cnt[2]={};
    REP(i,n) {
        sum+=a[i];
        tot-=a[i];
        cnt[a[i]/1000-1]++;
        if ( sum/10>tot ) break;
    }
    const int K=15;
    int l1=max(0,cnt[0]-K),r1=cnt[0]+K;
    int l2=max(0,cnt[1]-K),r2=cnt[1]+K;
    dump(l1,r1,l2,r2);
    int ans=INF;
    REP1(i,l1,r1) REP1(j,l2,r2) chkmin(ans,f(i,j));
    return ans;
}

int main() {
    R(n);
    REP(i,n) R(a[i]);
    // n=300000;
    // REP(i,n) a[i]=(rand()%2+1)*1000;
    REP(i,n) s[i+1]=s[i]+a[i];
    int ans=solve2();
    W(ans);
#ifdef SHIK
    if ( n<20 ) {
        auto slow_ans=slow();
        if ( ans!=slow_ans ) {
            dump(ans,slow_ans);
            assert(0);
        }
    }
#endif
    return 0;
}