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
    int n, m;
    string s;
    ve< pa< pii, pii > > rules;
    string t;
	bool read () {
        if (!(cin >> s)) {
            return 0;
        }
        cin >> n >> m;
        rules.resize(m);
        forn(i, m) {
            int p1, p2;
            char t1, t2;
            cin >> p1 >> t1 >> p2 >> t2;
            --p1, --p2;
            rules[i] = mp(mp(p1, t1 == 'V'), mp(p2, t2 == 'V'));
        }
        cin >> t;
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    string ans;	
	void write () {
        cout << ans << '\n';
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

const int MAXN = 500;

struct Solution: Data {
    int can_go[MAXN][2];
    ve< vi > to, tg;
    vi used_t;
    void dfs(int x) {
        used_t[x] = 1;
        for (auto v : to[x]) {
            if (!used_t[v]) dfs(v);
        }
    }
    bool build_2sat(int n)
    {
        forn(i, n) {
            used_t.assign(2 * n, 0);
            dfs(2 * i);
            can_go[i][0] = used_t[2 * i + 1];
            used_t.assign(2 * n + 1, 0);
            dfs(2 * i + 1);
            can_go[i][1] = used_t[2 * i];
            if (can_go[i][0] && can_go[i][1]) return false;
        }
        return true;
    }
    bool check_2sat(vi bits, int len)
    {
        used_t.assign(2 * n, 0);
        forn(i, len) {
            int exp = 2 * i + bits[i];
            if (used_t[exp ^ 1] || can_go[i][bits[i]]) {
                return false;
            }
            if (!used_t[exp]) dfs(exp);
        }
        return true;
    }
    
    char ls[2];

	void solve () {
        ans = "-1";
        ls[0] = ls[1] = '\0';
        forn(i, sz(s)) {
            ls[s[i] == 'V'] = i + 'a';
        }
        to.resize(2 * n);
        tg.resize(2 * n);
        forn(i, m) {
            int p1, t1, p2, t2;
            tie(p1, t1) = rules[i].fs;
            tie(p2, t2) = rules[i].sc;
            to[p1 * 2 + t1].pb(p2 * 2 + t2);
            tg[p2 * 2 + t2].pb(p1 * 2 + t1);
            to[p2 * 2 + 1 - t2].pb(p1 * 2 + 1 - t1);
            tg[p1 * 2 + 1 - t1].pb(p2 * 2 + 1 - t2);
        }
        if (!build_2sat(n)) return;
        vi bans;
        forn(i, sz(t)) {
            bans.pb(s[t[i] - 'a'] == 'V');
        }
        if (!ls[0] || !ls[1]) {
            if (check_2sat(bans, n)) {
                ans = t;
            }
            return;
        }
        int len = sz(t);
        int ret[2] = {0, 0};
        while (len) {
            debug(mt(len, bans));
            forn(i, 2) {
                bans.back() = i;
                ret[i] = check_2sat(bans, len);
            }
            if ((ret[0] && ls[0] >= t[len - 1]) || (ret[1] && ls[1] >= t[len - 1])) {
                break;
            }
            do {
                t[len - 1] = 'a';
                bans.pop_back();
                --len;
            } while (len && t[len - 1] + 1 - 'a' == sz(s));
            if (len) {
                t[len - 1]++;
                bans.back() = (t[len - 1] == 'V');
            }
        }
        if (!len) {
            return;
        }
        ans = t.substr(0, len - 1);
        while (len <= n) {
            debug(mt(len, bans));
            forn(i, 2) {
                bans.back() = i;
                ret[i] = check_2sat(bans, len);
            }
            char cur_s = t[len - 1];
            while (cur_s < 'a' + sz(s)) {
                if (ret[s[cur_s - 'a'] == 'V']) {
                    break;
                }
                ++cur_s;
            }
            assert(cur_s < 'a' + sz(s));
            ans += cur_s;
            bans.back() = (s[cur_s - 'a'] == 'V');
            bans.pb(0);
            ++len;
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