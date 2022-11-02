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

#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
struct Maxflow {
    struct E {
        int to,cap,rev,rcap,ucap;
        E() {}
        E( int _to, int _cap, int _rev ):to(_to),cap(_cap),rev(_rev),rcap(_cap) {}
    };
    int n;
    vector< vector<E> > e;
    vector< vector<E>::iterator > cur;
    vector<int> dis;
    void init( int _n ) {
        n=_n;
        e.resize(n);
        cur.resize(n);
        dis.resize(n);
        REP(i,n) e[i].clear();
    }
    void add( int a, int b, int c ) {
        if ( a==b ) return;
        e[a].PB(E(b,c,e[b].size()));
        e[b].PB(E(a,0,e[a].size()-1));
    }
    bool bfs() {
        fill(dis.begin(),dis.end(),-1);
        queue<int> q;
        dis[0]=0; q.push(0);
        while ( !q.empty() && dis[n-1]==-1 ) {
            int p=q.front(); q.pop();
            FOR(it,e[p]) {
                if ( it->cap==0 || dis[it->to]!=-1 ) continue;
                dis[it->to]=dis[p]+1;
                q.push(it->to);
            }
        }
        return dis[n-1]!=-1;
    }
    LL go( int p, LL c ) {
        if ( p==n-1 ) return c;
        LL ret=0;
        for ( ; cur[p]!=e[p].end(); cur[p]++ ) {
            if ( cur[p]->cap==0 || dis[cur[p]->to]!=dis[p]+1 ) continue;
            LL now=go(cur[p]->to,min((LL)cur[p]->cap,c-ret));
            ret+=now;
            cur[p]->cap-=now;
            e[cur[p]->to][cur[p]->rev].cap+=now;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow() {
        LL ret=0;
        while ( bfs() ) {
            REP(i,n) cur[i]=e[i].begin();
            ret+=go(0,1LL<<60);
        }
        return ret;
    }
    bool _addPath(int wh, vector< vector<int> > &ans){
        if(wh == n - 1){
            ans.PB(vector<int>());
            ans.back().PB(wh);
            return true;
        }
        FOR(it, e[wh]) if(it->ucap > 0 && _addPath(it->to, ans)){
            it->ucap--;
            ans.back().PB(wh);
            return true;
        }
        return false;
    }
    vector< vector<int> > getPath(){
        vector< vector<int> > ans;
        FOR(it, e) FOR(jt, *it) jt->ucap = max(0, jt->rcap - jt->cap);
        while(_addPath(0, ans)) reverse(ans.back().begin(), ans.back().end());
        return ans;
    }
} flow;

const int N=5010;
const int M=5010;
int n,m,a[M],b[M],din[N],dot[N];

bool chk( int k, bool flag ) {
    int sink=n+1;
    flow.init(sink+1);
    REP(i,m) flow.add(a[i],b[i],1);
    int g=0;
    REP1(i,1,n) {
        if ( dot[i]>k ) {
            g+=dot[i]-k;
            flow.add(0,i,dot[i]-k);
        } else {
            flow.add(i,sink,k-dot[i]);
        }
    }
    int f=flow.maxflow();
    if ( f<g ) return 0;
    if ( flag ) {
        auto ps=flow.getPath();
        set<PII> rev;
        for ( auto p:ps ) REP(i,SZ(p)-1) rev.insert(MP(p[i],p[i+1]));
        REP(i,m) {
            auto p=MP(a[i],b[i]);
            if ( !rev.count(p) ) W(a[i],b[i]);
            else W(b[i],a[i]);
        }
    }
    return 1;
}

int main() {
    R(n,m);
    REP(i,m) R(a[i],b[i]);
    REP(i,m) {
        dot[a[i]]++;
        din[b[i]]++;
    }
    int l=0,r=n;
    while ( l!=r ) {
        int mid=(l+r)/2;
        if ( chk(mid,0) ) r=mid;
        else l=mid+1;
    }
    W(l);
    chk(l,1);
    return 0;
}