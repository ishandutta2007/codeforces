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

// typedef long double ld;
typedef double ld;

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

const int MAXD = 60;

struct Input {
	
    int q;
    vi tp;
    vi v;

	bool read () {
        if (scanf("%d", &q) != 1) return 0;
        tp.resize(q);
        v.resize(q);
        forn (i, q) {
            scanf("%d%d", &tp[i], &v[i]);
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	
    ve< ld > ans;
	void write () {
        for (auto x : ans) {
            printf("%.13lf\n", double(x));
        }
	}
};

struct Solution: Data {
	
    int cnt;
    int par[500100];

    ld prob[500100][MAXD];

    void init_lprob(int x) {
        prob[x][0] = 1;
        forn (i, 1, MAXD) {
            prob[x][i] = 0;
        }
    }

    void add_ver(int x) {
        int next_ver = ++cnt;
        par[next_ver] = x;
        init_lprob(next_ver);
        ld ratio = ld(0.5);
        int cur_len = 0;
        int cur_v = next_ver;
        while (par[cur_v] && cur_len < MAXD - 1) {
            cur_v = par[cur_v];
            cur_len++;
            ld old_prob = prob[cur_v][cur_len];
            prob[cur_v][cur_len] = 1 - (1 - old_prob) * ratio;
            ratio = (1 - prob[cur_v][cur_len] / 2.) / (1 - old_prob / 2.);
        }
    }

    ld get_ans(int x) {
        ld res = 0;
        forn (i, 1, MAXD) {
            res += prob[x][i]; 
        }
        return res;
    }

	void solve () {
        memset(prob, 0, sizeof(prob));
        memset(par, 0, sizeof(par));
        cnt = 1;
	    par[1] = 0;
        init_lprob(1);
        forn (i, q) {
            if (tp[i] == 1) {
                add_ver(v[i]);
            } else {
                ans.pb(get_ans(v[i]));
            }
        }
	}
	
	void clear () {
		*this = Solution();
        debug();
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