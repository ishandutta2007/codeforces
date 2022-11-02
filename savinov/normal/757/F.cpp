//
// Created by Evgeny Savinov on 09/01/2017.
//

#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
//typedef pair<int, int> pii;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

class range {
    using type = long long;
public:
    class iterator {
        friend class range;

    public:
        using difference_type = range::type;
        using value_type = range::type;
        using pointer = const range::type *;
        using reference = const range::type &;
        using iterator_category = std::random_access_iterator_tag;

        value_type operator*() const { return i_; }

        const iterator &operator++() {
            ++i_;
            return *this;
        }

        iterator operator++(int) {
            iterator copy(*this);
            ++i_;
            return copy;
        }

        const iterator &operator--() {
            --i_;
            return *this;
        }

        iterator operator--(int) {
            iterator copy(*this);
            --i_;
            return copy;
        }

        difference_type operator-(const iterator &other) const { return i_ - other.i_; }

        iterator operator+(const difference_type &delta) const { return iterator(i_ + delta); }

        iterator &operator+=(const difference_type &delta) {
            i_ += delta;
            return *this;
        }

        iterator operator-(const difference_type &delta) const { return iterator(i_ - delta); }

        iterator &operator-=(const difference_type &delta) {
            i_ -= delta;
            return *this;
        }

        bool operator==(const iterator &other) const { return i_ == other.i_; }

        bool operator!=(const iterator &other) const { return i_ != other.i_; }

    protected:
        iterator(const value_type &start) : i_(start) {}

    private:
        value_type i_;
    };

    iterator begin() const { return begin_; }

    iterator end() const { return end_; }

    range(const type &begin, const type &end) : begin_(begin), end_(end) {}

    range(const type &end) : begin_(0), end_(end) {}

private:
    iterator begin_;
    iterator end_;
};

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);

class range;

mt19937 gen;

int TTT;

ll mod = 1000000007;


void pre() {

}

namespace DOM {
    const int N=1e6+5,M=1e6+5;
    int cnt,dfn_cnt,last[N],lastpre[N],lastsdom[N],dfn[N],id[N],par[N],fa[N],best[N],sdom[N],idom[N],size[N];
    struct edge{int y,last;}E[M*2+N];
    int find(int x)
    {
        if (x==fa[x]) return x;
        int y=find(fa[x]);
        if (dfn[sdom[best[fa[x]]]]<dfn[sdom[best[x]]]) best[x]=best[fa[x]];
        return fa[x]=y;
    }
    void link(int *last,int x,int y) {E[cnt]=(edge){y,last[x]},last[x]=cnt++;}
    void dfs(int p)
    {
        dfn[p]=dfn_cnt,id[dfn_cnt]=p,++dfn_cnt;
        for (int i=last[p],nxt;~i;i=E[i].last) if (!~dfn[nxt=E[i].y]) par[nxt]=p,dfs(nxt);
    }
    void calc(int n)
    {
        for (int i=0,num;i<n;++i) num=id[i],fa[num]=num,best[num]=num,sdom[num]=num;
        for (int i=n-1,p;i;--i)
        {
            p=id[i];
            for (int j=lastpre[p],nxt;~j;j=E[j].last) if (~dfn[nxt=E[j].y])
                {
                    find(nxt);
                    if (dfn[sdom[best[nxt]]]<dfn[sdom[p]]) sdom[p]=sdom[best[nxt]];
                }
            link(lastsdom,sdom[p],p),fa[p]=par[p];
            p=id[i-1];
            for (int j=lastsdom[p],nxt;~j;j=E[j].last)
            {
                find(nxt=E[j].y);
                if (sdom[best[nxt]]==p) idom[nxt]=p; else idom[nxt]=best[nxt];
            }
        }
        for (int i=1,p;i<n;++i)
        {
            p=id[i];
            if (idom[p]!=sdom[p]) idom[p]=idom[idom[p]];
        }
    }
}

void solve(int test) {
    int n = nxt();

    int m = nxt();

    int s = nxt() - 1;


    vll dist(n, LLONG_MAX);

    vector <pair <int, int> > g[n];

    forn(i, m) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        int w = nxt();

        g[u].pb({v, w});
        g[v].pb({u, w});
    }


    auto cmp = [&](int u, int v) {
        if (dist[u] != dist[v]) {
            return dist[u] < dist[v];
        }
        return u < v;
    };

    set <int, decltype(cmp)> q(cmp);

    dist[s] = 0;
    q.insert(s);

    int cnt = 0;

    vi used(n);

    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        used[v] = 1;
        ++cnt;

        for (auto e : g[v]) {
            int to = e.x;
            ll nlen = dist[v] + e.y;

            if (nlen < dist[to]) {
                q.erase(to);
                dist[to] = nlen;
                q.insert(to);
            }
        }
    }

    memset(DOM::dfn,-1,sizeof(int)*n);
    memset(DOM::last,-1,sizeof(int)*n);
    memset(DOM::lastpre,-1,sizeof(int)*n);
    memset(DOM::lastsdom,-1,sizeof(int)*n);


    for (int i = 0; i < n; ++i) {
        if (!used[i]) continue;
        for (auto to : g[i]) {
            if (!used[to.x]) continue;
            if (dist[to.x] == dist[i] + to.y) {
                int x = i;
                int y = to.x;
                DOM::link(DOM::last,x,y);
                DOM::link(DOM::lastpre,y,x);
            }
        }
    }
    DOM::dfs(s);
    DOM::calc(DOM::dfn_cnt);

    int ans = 0;

    for (int i=DOM::dfn_cnt-1,p;i;--i)
    {
        p=DOM::id[i],++DOM::size[p];
        ans = max(ans, DOM::size[p]);
        DOM::size[DOM::idom[p]]+=DOM::size[p];
    }

    cout << ans << "\n";
}

int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    ::TTT = 1;
#ifdef LOCAL
#else
#endif

    for (int test = 1; test <= ::TTT; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}


template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}


template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}


template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = long long>
inline T nxt() {
    T res;
    input(res);
    return res;
}

void myassert(bool v) {
    assert(v);
//cout << "FAIL\n";
//exit(0);
}

mt19937 generator;

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

template<typename T>
T pw(T a, T n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template<typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}


template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}