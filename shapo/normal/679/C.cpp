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

    int n, k;
    ve< vi > block;
	
	bool read () {
        if (scanf("%d%d", &n, &k) != 2) return 0;
        char buf[1000];
        block.assign(n, vi(n, 0));
        forn (i, n) {
            scanf(" %s", buf);
            forn (j, n) {
                block[i][j] = (buf[j] == 'X');
            }
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {

    int ans;
	
	void write () {
		printf("%d\n", ans);
	}
};

const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};

struct Solution: Data {

    ve< vi > color;
    vi cnt;

    void dfs(int x, int y, int cl) {
        color[x][y] = cl;
        cnt[cl]++;
        forn (dir, 4) {
            int cx = x + DX[dir], cy = y + DY[dir];
            if (cx >= 0 && cx < n && cy >= 0 && cy < n && !block[cx][cy] && color[cx][cy] == -1) {
                dfs(cx, cy, cl); 
            }
        }
    }

    int check_pnt(int px, int py, int val, vi &tm) {
        if (px >= 0 && px < n && py >= 0 && py < n && !block[px][py] && tm[color[px][py]] != val) {
            tm[color[px][py]] = val;
            return cnt[color[px][py]];
        }
        return 0;
    }

	void solve () {
        deepen(0);
        ve< vi > dp;
        ans = 0;
        color.assign(n, vi(n, -1));
        cnt.clear();
        forn (i, n) {
            forn (j, n) {
                if (!block[i][j] && color[i][j] == -1) {
                    cnt.pb(0);
                    dfs(i, j, sz(cnt) - 1);
                }
            }
        }
        vi tm(sz(cnt));
        int _tm = 0;
        dp.assign(n - k + 1, vi(n - k + 1, 0));
        debug(color);
        debug(cnt);
        forn (i, n - k + 1) {
            forn (j, k) {
                forn (d, k) {
                    if (!block[i + d][j]) {
                        cnt[color[i + d][j]]--;
                    }
                }
            }
            forn (j, n - k + 1) {
                ++_tm;
                int cur = k * k;
                forn (d, k) {
                    cur += check_pnt(i - 1, j + d, _tm, tm)
                        +  check_pnt(i + k, j + d, _tm, tm)
                        +  check_pnt(i + d, j - 1, _tm, tm) 
                        +  check_pnt(i + d, j + k, _tm, tm);
                }
                dp[i][j] += cur;
                umx(ans, dp[i][j]);
                if (j != n - k) {
                    forn (d, k) {
                        if (!block[i + d][j]) {
                            cnt[color[i + d][j]]++;
                        }
                        if (!block[i + d][j + k]) {
                            cnt[color[i + d][j + k]]--;
                        }
                    }
                }
            }
            forn (j, k) {
                forn (d, k) {
                    if (!block[i + d][n - j - 1]) {
                        cnt[color[i + d][n - j - 1]]++;
                    }
                }
            }
            debug(cnt);
        }
        debug(dp);
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