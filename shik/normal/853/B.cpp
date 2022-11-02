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

const int N=1e5+10;
const LL INF=1e12;

struct E {
    int d,w;
    LL c;
};

bool operator <( const E &a, const E &b ) {
    return a.d<b.d;
}

int n,m,k;
LL cf[N],ct[N];
vector<PII> fm[N],to[N];
int main() {
    R(n,m,k);
    REP(i,m) {
        int d,f,t,c;
        R(d,f,t,c);
        if ( t==0 ) fm[f].PB({d,c});
        else if ( f==0 ) to[t].PB({d,c});
        else assert(0);
    }
    REP1(i,1,n) if ( fm[i].empty() || to[i].empty() ) {
        W(-1);
        return 0;
    }
    vector<E> ef,et;
    REP1(i,1,n) {
        sort(ALL(fm[i]));
        sort(ALL(to[i]));
        REP1(j,1,SZ(fm[i])-1) chkmin(fm[i][j].second,fm[i][j-1].second);
        for ( int j=SZ(to[i])-2; j>=0; j-- ) chkmin(to[i][j].second,to[i][j+1].second);
        for ( auto j:fm[i] ) ef.PB({j.first,i,j.second});
        REP(j,SZ(to[i])-1) et.PB({to[i][j].first,i,to[i][j+1].second});
        et.PB({to[i].back().first,i,INF});
    }
    sort(ALL(ef));
    sort(ALL(et));
    LL ans=INF;
    REP1(i,1,n) cf[i]=INF;
    REP1(i,1,n) ct[i]=to[i][0].second;
    LL now=0;
    REP1(i,1,n) now+=cf[i]+ct[i];
    auto fi=ef.begin(),ti=et.begin();
    REP1(i,1,1000000) {
        while ( ti!=et.end() && ti->d<=i+k-1 ) {
            now-=ct[ti->w];
            ct[ti->w]=ti->c;
            now+=ct[ti->w];
            ti++;
        }
        if ( now<ans ) dump(i,now);
        chkmin(ans,now);
        while ( fi!=ef.end() && fi->d<=i ) {
            now-=cf[fi->w];
            cf[fi->w]=fi->c;
            now+=cf[fi->w];
            fi++;
        }
    }
    W(ans<INF ? ans : -1);
    return 0;
}