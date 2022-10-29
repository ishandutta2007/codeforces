#include <bits/stdc++.h>
using namespace std;

#ifdef SG
    #include <debug.h>
#else
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int MAXN = 800500;

struct Input {
    ve< string > t, q;
    int n;
    char buf[MAXN];
    bool read () {
        if (scanf("%d", &n) != 1) {
            return 0;
        }
        t.resize(n);
        q.resize(n);
        forn(i, n) {
            scanf(" %s", buf);
            int l = strlen(buf);
            t[i] = string(buf, buf + l);
        }
        forn(i, n) {
            scanf(" %s", buf);
            int l = strlen(buf);
            q[i] = string(buf, buf + l);
        }
        return 1;
    }

    void init (const Input &input) {
        *this = input;
    }
};

struct Data: Input {
    ll ans;
    vi corr;
    void write () {
        printf("%" PRId64 "\n", ans);
        forn(i, n) {
            printf("%d %d\n", i + 1, corr[i] + 1);
        }   
    }
    
    virtual void solve () {}
    
    virtual void clear () {
        *this = Data();
    }
};

const int MAXL = 1000500;
const int ALPH = 26;

struct Solution: Data {
    vi tt[MAXN], qq[MAXL];
    int to[MAXL][ALPH];
    int cnt;
    void add_str(const string &s, int pos)
    {
        int root = 1;
        for (char c : s) {
            int cc = c - 'a';
            if (!to[root][cc]) {
                to[root][cc] = ++cnt;
            }   
            root = to[root][cc];
        }
        if (pos > 0) {
            tt[root].pb(pos - 1);
        } else {
            qq[root].pb(-pos - 1);
        }   
    }
    bool merge_v(vi &a, vi &b)
    {
        debug(mt(a, b));
        bool ret = sz(a) <= sz(b);
        if (!ret) {
            a.insert(a.end(), all(b));
            b.clear();
            debug(a);
        } else {
            b.insert(b.end(), all(a));
            a.clear();
            debug(b);
        }
        debug(ret);
        return ret;
    } 
    void rec(int v, int depth, int &qid, int &tid, string &s)
    {   
        deepen(0);
        int tqid = v, ttid = v;
        s += 'a';
        forn(i, ALPH) {
            if (to[v][i]) {
                int fqid = 0, ftid = 0;
                s.back() = i + 'a';
                rec(to[v][i], depth + 1, fqid, ftid, s);
                if (merge_v(qq[tqid], qq[fqid])) {
                    tqid = fqid;
                }
                if (merge_v(tt[ttid], tt[ftid])) {
                    ttid = ftid;
                }
                debug(mt(tqid, ttid));
                debug(mt(qq[tqid], tt[ttid]));
            }
        }
        debug(qq, qq + cnt + 1);
        debug(tt, tt + cnt + 1);
        s.pop_back();   
        qid = tqid, tid = ttid; 
        debug(mt(v, s, tt[ttid], qq[tqid]));
        while (sz(tt[ttid]) && sz(qq[tqid])) {
            int cur_t = tt[ttid].back();
            int cur_q = qq[tqid].back();
            tt[ttid].pop_back();
            qq[tqid].pop_back();
            ans += depth;
            corr[cur_t] = cur_q;
        }
    }
    void solve () {
        cnt = 1;
        ans = ll(0);
        corr.assign(n, -1);
        forn(i, n) {
            add_str(t[i], i + 1);
            add_str(q[i], -(i + 1));
        }   
        int tv = 0, qv = 0;
        string tmp_s = "";
        rec(1, 0, tv, qv, tmp_s);
    }
    
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
    freopen((problemname + ".in").c_str(), "r", stdin);
//  freopen((problemname + ".out").c_str(), "w", stdout);
    while (sol.read()) {
        sol.solve();
        sol.write();
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif  
    return 0;
}