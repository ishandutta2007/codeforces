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
    static const int MAXN = 300500;

    int n;
    vi c;
    char s[MAXN];
    ve< vi > g;
	
	bool read () {
        if (scanf("%d", &n) != 1) return 0;
        c.resize(n);
        forn (i, n) {
            scanf("%d", &c[i]);
        }
        scanf(" %s", s);
        g.resize(n);
        forn (i, n - 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u, --v;
            g[u].pb(v);
            g[v].pb(u);
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    int val, num;	
	void write () {
		printf("%d %d\n", val, num);
	}
};

struct Solution: Data {
	
    typedef map< char, int > tv;
    typedef ve< tv > trie;

    vi cnt;
    vi tr;

    void traverse(trie &dst, int pd, const trie &src, int ps) {
        for (const auto &vl : src[ps]) {
            int x; char c;
            tie(c, x) = vl;
            if (!dst[pd].count(c)) {
                dst[pd][c] = sz(dst);
                dst.pb(tv());
            }
            traverse(dst, dst[pd][c], src, x);
        }
    }

    void dfs(int x, int pr, trie &root) {
        {
            int tmp = tr[x];
            tr[x] = sz(root);
            root.pb(tv());
            root[tr[x]][s[x]] = tmp;
        }
        for (int to : g[x]) {
            if (to == pr) continue;
            trie chroot(1);
            dfs(to, x, chroot);
            {
                int tmp = tr[to];
                tr[to] = sz(chroot);
                chroot.pb(tv());
                chroot[tr[to]][s[x]] = tmp;
            }
            if (sz(root) < sz(chroot)) {
                chroot.swap(root);
                swap(tr[x], tr[to]);
            }
            traverse(root, tr[x], chroot, tr[to]);
            chroot.clear();
        }
        cnt[x] = sz(root) - 1;
    }

	void solve () {
	    trie ans(1);
        cnt.assign(n, 0);
        tr.assign(n, 0);
        dfs(0, -1, ans);
        val = 0, num = 0;
        vi sum(n);
        forn (i, n) {
            sum[i] = c[i] + cnt[i];
            if (umx(val, sum[i])) {
                num = 0;
            }
            if (val == sum[i]) {
                num++;
            }
        }
        debug(c);
        debug(cnt);
        debug(sum);
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