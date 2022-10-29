#include <bits/stdc++.h>
using namespace std;

#if defined(__linux__)
#include <sys/resource.h>
#include <sys/time.h>
#endif

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
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
    int n, m;	
	bool read () {
        return (scanf("%d%d", &n, &m) == 2);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    ll ans[500100];
    int acnt;
	void write () {
        forn(i, acnt) {
            printf("%" PRId64 "\n", ll(ans[i]));
        }
	}
};

const int MAXV = 500100;
const int MAXL = 19;

struct Solution: Data {
    int vcnt;
    ll sum[MAXL][MAXV];
    int par[MAXL][MAXV]; 
    int timer[MAXV];
    int valid[MAXV], tr[MAXV];
    pii q[MAXV];
    int tm[MAXV];
    int qcnt;
    int cnt[MAXV];
    int pv[MAXV];
    ve< vi > sons;
    int last_time[MAXV], add[MAXV];
    void add_par_u(int a, int b, int ct)
    {
        int nv = vcnt++;
        cnt[a] += cnt[b];
        if (valid[b] == -1) {
            tr[b] = nv;
        } else {
            par[0][valid[b]] = nv;
        }
        if (valid[a] == -1) {
            tr[a] = nv;
        } else {
            par[0][valid[a]] = nv;
        }
        timer[nv] = ct;
        valid[a] = valid[b] = nv;
    }
    void add_par_v(int c, int d, int ct)
    {
        c = get_par(c), d = get_par(d);
        if (sz(sons[d]) > sz(sons[c])) swap(c, d);
        for (int x : sons[d]) {
            if (add[x] <= last_time[d]) {
                umx(last_time[x], last_time[d]);
            }
            add[x] = ct;
        }
        sons[c].insert(sons[c].end(), all(sons[d]));
        vi().swap(sons[d]);
        pv[d] = c;
    }
    int get_par(int x)
    {
        return (pv[x] != x) ? get_par(pv[x]) : pv[x];
    }
    void add_all(int x, int ct)
    {
        int nv = vcnt++;
        if (valid[x] == -1) {
            tr[x] = nv;
        } else {
            par[0][valid[x]] = nv;
        }
        timer[nv] = ct;
        sum[0][nv] = cnt[x];
        valid[x] = nv;
    }
    ll get_ans_t(int v, int from)
    {
        int cur = tr[v];
        ll res = 0ll;
        ford(it, MAXL) {
            int nxt = par[it][cur];
            if (nxt != -1 && timer[nxt] <= from) {
                res += sum[it][cur];
                cur = nxt;
            }
        }
        if (timer[cur] <= from) res += sum[0][cur];
        debug(mt(v, from, res));
        return res;
    }
    ll get_ans(int v, int ct)
    {
        if (valid[v] == -1) return 0ll;
        int x = get_par(v);
        int t1 = ct, t2 = last_time[v];
        if (add[v] <= last_time[x]) {
            umx(t2, last_time[x]);
        }
        debug(mt(t1, t2));
        return max(ll(0), get_ans_t(v, t1) - get_ans_t(v, t2));
    }
	void solve () {
        memset(par, -1, sizeof(par));
        memset(sum, 0, sizeof(sum));
        vcnt = 0;
        qcnt = 0;
        sons.resize(n);
        forn(i, n) {
            cnt[i] = 1;
            pv[i] = i;
            last_time[i] = add[i] = 0;
            valid[i] = tr[i] = -1;
            sons[i].pb(i);
        }
        forn(i, 1, m + 1) {
            char w;
            scanf(" %c", &w);
            if (w == 'U') {
                int a, b;
                scanf("%d%d", &a, &b);
                --a, --b;
                assert(a != b);
                add_par_u(a, b, i);
            } else if (w == 'M') {
                int c, d;
                scanf("%d%d", &c, &d);
                assert(c != d);
                --c, --d;
                tm[qcnt] = i;
                q[qcnt++] = mp(-c - 1, -d - 1);
            } else if (w == 'A') {
                int x;
                scanf("%d", &x);
                --x;
                add_all(x, i);
            } else if (w == 'Z') {
                int y;
                scanf("%d", &y);
                --y;
                q[qcnt++] = mp(-y - 1, i);
            } else {
                int qq;
                scanf("%d", &qq);
                --qq;
                q[qcnt++] = mp(qq, i);
            }
        }
        forn(it, 1, MAXL) {
            forn(i, vcnt) {
                int nxt = par[it - 1][i];
                if (nxt != -1) {
                    par[it][i] = par[it - 1][nxt];
                    sum[it][i] = sum[it - 1][i] + sum[it - 1][nxt];
                }
            }
        }
        acnt = 0;
        forn(i, qcnt) {
            auto pr = q[i];
            int id = pr.fs, ct = pr.sc;
            if (id < 0) {
                id = -id - 1;
                if (ct < 0) {
                    ct = -ct - 1;
                    add_par_v(id, ct, tm[i]);
                } else {
                    last_time[get_par(id)] = ct;
                }
            } else {
                ans[acnt++] = get_ans(id, ct);
            }
        }
	}
	
	void clear () {
        cout << endl;
		*this = Solution();
	}
};

Solution sol;

int main () {
#ifdef SG
	while (sol.read()) {
		sol.solve();
		sol.write();
		// sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
#if defined(__linux__)
    struct rusage info;
    getrusage(RUSAGE_SELF, &info);
    cerr << info.ru_maxrss << "KiB" << endl;
#endif
	return 0;
}