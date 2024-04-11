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
	int n;
    ve< vi > g;
	bool read () {
        if (!(cin >> n)) return 0;
        g.resize(n);
        forn(i, n - 1) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            g[a].pb(b);
            g[b].pb(a);
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    bool ans;	
	void write () {
		cout << (ans ? "Yes" : "No") << '\n';
	}
};

const int N = 100500;

struct Solution: Data {
	
    int can[N][2][2];

    int find_cand(int x, int par)
    {
        memset(can[x], 1, sizeof(can[x]));
        vi sons;
        for (int to : g[x]) {
            if (to == par) continue;
            int res = find_cand(to, x);
            if (res != -1) return res;
            sons.pb(to);
        }
        if (sz(sons) > 1 || (sz(sons) == 1 && !can[sons[0]][0][0])) {
            can[x][0][0] = 0;
        }
        if (sz(sons) > 2 || (sz(sons) == 2 && (!can[sons[0]][0][0] || !can[sons[1]][0][0]))
                || (sz(sons) == 1 && !can[sons[0]][0][0])) {
            can[x][0][1] = 0;
        }
        for (int to : sons) {
            if (!can[to][0][1] && !can[to][0][0]) {
                return to;
            }
        }
        return -1;
    }

    void dfs(int x, int par) {
        memset(can[x], 1, sizeof(can[x]));
        vi sons;
        for (int to : g[x]) {
            if (to == par) continue;
            dfs(to, x);
            sons.pb(to);
        }
        if (sz(sons) > 1 || (sz(sons) == 1 && !can[sons[0]][0][0])) {
            can[x][0][0] = 0;
        }
        if (sz(sons) > 2 || (sz(sons) == 2 && (!can[sons[0]][0][0] || !can[sons[1]][0][0]))
                || (sz(sons) == 1 && !can[sons[0]][0][0])) {
            can[x][0][1] = 0;
        }
        vi cnt2;
        for (int to : sons) {
            if (!can[to][0][0] && !can[to][0][1]) {
                cnt2.pb(to);
            }
        }
        if (sz(cnt2) > 1 || (sz(cnt2) == 1 && !can[cnt2[0]][1][0])) {
            can[x][1][0] = 0;
        }
        if (sz(cnt2) > 2 || (sz(cnt2) == 2 && (!can[cnt2[0]][1][0] || !can[cnt2[1]][1][0]))
                || (sz(cnt2) == 1 && !can[cnt2[0]][1][0])) {
            can[x][1][1] = 0;
        }
    }

	void solve () {
        memset(can, 0, sizeof(can));
        int id = find_cand(0, -1);
        if (id == -1) {
            ans = 1;
            return;
        }
        memset(can, 0, sizeof(can));
        dfs(id, -1);
        ans = 0;
        forn(i, 2) {
            forn(j, 2) {
                if (can[id][i][j]) ans = 1;
            }
        }
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