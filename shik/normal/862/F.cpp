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

template<typename T>
struct SegTreeRangeAsk {
    int n;
    vector<T> dat;
    template<typename F>
    void init(int id, int l, int r, F f) {
        if (l == r) {
            dat[id] = f(l);
            return;
        }
        int m = (l + r) / 2;
        init(id * 2, l, m, f);
        init(id * 2 + 1, m + 1, r, f);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    template<typename F>
    void init(int _n, F f) {
        n = _n;
        dat.resize(4 * (n + 1));
        init(1, 1, n, f);
    }
    void init(int _n, T *a) {
        init(_n, [a](int i) { return a[i]; });
    }
    void init(int _n, T val) {
        init(_n, [val](int) { return val; });
    }
    T ask(int id, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return dat[id];
        int m = (l + r) / 2;
        if (qr <= m) return ask(id * 2, l, m, ql, qr);
        if (ql > m) return ask(id * 2 + 1, m + 1, r, ql, qr);
        T tl = ask(id * 2, l, m, ql, qr);
        T tr = ask(id * 2 + 1, m + 1, r, ql, qr);
        return tl + tr;
    }
    T ask(int l, int r) {
        assert(l <= r);
        return ask(1, 1, n, l, r);
    }
    void chg(int id, int l, int r, int qx, T qv) {
        if (l == r) {
            dat[id] = qv;
            return;
        }
        int m = (l + r) / 2;
        if (qx <= m) chg(id * 2, l, m, qx, qv);
        else chg(id * 2 + 1, m + 1, r, qx, qv);
        dat[id] = dat[id * 2] + dat[id * 2 + 1];
    }
    void chg(int qx, T qv) {
        assert(1 <= qx && qx <= n);
        chg(1, 1, n, qx, qv);
    }
};

int lcp( const string &a, const string &b ) {
    int l=0;
    while ( l<SZ(a) && l<SZ(b) && a[l]==b[l] ) l++;
    return l;
}

struct Max {
    int x;
    Max operator+(const Max &other) {
        return {max(x, other.x)};
    }
};

SegTreeRangeAsk<Max> seg_len;

const int L=64;
struct Lcp {
    int l,r,cl[L],cm[L],cr[L];
    int len() const { return r-l+1; }
    int eval() const {
        int mx=0;
        REP(i,L) if ( cm[i] ) chkmax(mx,(i+1)*(cm[i]+1));
        return mx;
    }
};
Lcp operator+(const Lcp &a, const Lcp &b) {
    Lcp c;
    c.l=a.l;
    c.r=b.r;
    int na=a.len(),nb=b.len();
    REP(i,L) {
        c.cl[i]=(a.cl[i]<na ? a.cl[i] : na+b.cl[i]);
        c.cr[i]=(b.cr[i]<nb ? b.cr[i] : nb+a.cr[i]);
        c.cm[i]=max({a.cm[i],b.cm[i],a.cr[i]+b.cl[i]});
    }
    return c;
}
SegTreeRangeAsk<Lcp> seg_lcp;

const int N=1e5+10;

int n,m,h[N];
string s[N];

Max gen_max( int i ) { return Max{SZ(s[i])}; }
Lcp gen_lcp( int p ) {
    Lcp x;
    x.l=x.r=p;
    REP(i,L) x.cl[i]=x.cm[i]=x.cr[i]=(i<h[p]);
    return x;
}

set<int> ls;
int solve_ls( int l, int r ) {
    VI v;
    auto it=ls.lower_bound(l);
    while ( it!=ls.end() && *it<=r ) v.PB(*it++);
    VI a;
    REP(i,SZ(v)) {
        if ( i>0 && v[i]!=v[i-1]+1 ) a.PB(0);
        a.PB(h[v[i]]);
    }
    a.PB(0);
    int ans=0;
    VI stk;
    REP(i,SZ(a)) {
        while ( !stk.empty() && a[stk.back()]>=a[i] ) {
            int x=stk.back();
            stk.pop_back();
            int lb=stk.empty() ? 0 : stk.back() + 1;
            int rb=i-1;
            int now=a[x]*(rb-lb+2);
            chkmax(ans,now);
        }
        stk.PB(i);
    }
    return ans;
}

void solve_1() {
    while ( m-- ) {
        int op;
        cin>>op;
        if ( op==1 ) {
            int l,r;
            cin>>l>>r;
            cout<<SZ(s[1])<<'\n';
        } else if ( op==2 ) {
            int x;
            cin>>x;
            cin>>s[x];
        } else assert(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    REP1(i,1,n) cin>>s[i];
    if ( n==1 ) {
        solve_1();
        return 0;
    }
    REP1(i,1,n-1) h[i]=lcp(s[i],s[i+1]);
    seg_len.init(n,gen_max);
    seg_lcp.init(n-1,gen_lcp);
    REP1(i,1,n-1) if ( h[i]>L ) ls.insert(i);
    while ( m-- ) {
        int op;
        cin>>op;
        if ( op==1 ) {
            int l,r;
            cin>>l>>r;
            int ans=0;
            auto qlen=seg_len.ask(l,r);
            chkmax(ans,qlen.x);
            dump(l,r,qlen.x);
            if ( l<r ) {
                auto qlcp=seg_lcp.ask(l,r-1);
                chkmax(ans,qlcp.eval());
                auto qls=solve_ls(l,r-1);
                chkmax(ans,qls);
                dump(l,r,qlcp.eval(),qls);
            }
            cout << ans << '\n';
        } else if ( op==2 ) {
            int x;
            cin>>x;
            cin>>s[x];
            seg_len.chg(x,gen_max(x));
            if ( x-1>=1 ) {
                h[x-1]=lcp(s[x-1],s[x]);
                seg_lcp.chg(x-1,gen_lcp(x-1));
                if ( h[x-1]<=L ) ls.erase(x-1);
                else ls.insert(x-1);
            }
            if ( x+1<=n ) {
                h[x]=lcp(s[x],s[x+1]);
                seg_lcp.chg(x,gen_lcp(x));
                if ( h[x]<=L ) ls.erase(x);
                else ls.insert(x);
            }
        } else assert(0);
    }
    return 0;
}