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
const ld EPS = 1e-9;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

struct Input {
    int n;
    vi x, dist;
	
    bool read () {
        if (!(cin >> n)) {
            return 0;
        }
        x.resize(n + 2);
        forn(i, n + 2) {
            cin >> x[i];
        }
        dist.resize(n);
        forn(i, n) {
            cin >> dist[i];
            dist[i] *= 2;
        }
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
    ld ans;	
	void write () {
        cout << ans << '\n';
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	void solve () {
        ans = x.back() / 2.; 
        vi l_stack, r_stack;
        vi l_far(n + 2, 0), r_far(n + 2, x.back() + 1);
        // make left neighbours
        l_stack.pb(0);
        l_far[0] = x.back();
        forn(i, 1, n + 1) {
            while (l_far[l_stack.back()] < x[i]) {
                l_stack.pop_back();
            }
            int left_id = l_stack.back();
            if (x[i] - x[left_id] < dist[i - 1]) {
                l_far[i] = dist[i - 1] + x[left_id];
                if (l_far[i] >= x.back()) {
                    ans = 0.;
                    return;
                }
                while (l_far[l_stack.back()] < l_far[i]) {
                    l_stack.pop_back();
                }
                l_stack.pb(i);
            }
        }
        // make right neighbours
        r_stack.pb(n + 1);
        r_far[n + 1] = 0;
        ford(i, 1, n + 1) {
            while (r_far[r_stack.back()] > x[i]) {
                r_stack.pop_back();
            }
            int right_id = r_stack.back();
            if (x[right_id] - x[i] < dist[i - 1]) {
                r_far[i] = x[right_id] - dist[i - 1];
                if (r_far[i] <= 0) {
                    ans = 0.;
                    return;
                }
                while (r_far[r_stack.back()] > r_far[i]) {
                    r_stack.pop_back();
                }
                r_stack.pb(i);
            }
        }
        ve< vi > sparse(20, vi(n + 2, x.back()));
        sparse[0] = r_far;
        forn(it, 1, 20) {
            forn(i, n + 2) {
                sparse[it][i] = sparse[it - 1][i];
                if (i + (1 << (it - 1)) < n + 2) {
                    umn(sparse[it][i], sparse[it - 1][i + (1 << (it - 1))]);
                }
            }
        }
        debug(all(l_far));
        debug(all(r_far));
        forn(i, 0, n + 1) {
            if (l_far[i] == 0) {
                continue;
            }
            int cur_pos = i + 1;
            ford(it, 0, 20) {
                int nxt = cur_pos + (1 << it);
                if (nxt < n + 2 && sparse[it][cur_pos] > l_far[i]) {
                    cur_pos = nxt;
                }
            }
            debug(mp(i, cur_pos));
            debug(x[cur_pos] - x[i]);
            ans = min(ans, (x[cur_pos] - x[i]) / ld(2));
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
    ios_base::sync_with_stdio(false);
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