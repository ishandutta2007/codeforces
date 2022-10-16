#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")
#endif //LOCAL

#define _SCL_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:256000000")

#define first x
#define second y

#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <memory>
#include <chrono>

#ifdef LOCAL
//#include <vld.h>
#endif //LOCAL
using namespace std;

//typedef __int128_t ll;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double ld;

#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

#ifdef LOCAL
mt19937 rd(57322);
#else
mt19937 rd((uint)chrono::steady_clock::now().time_since_epoch().count());
#endif
/*------CommentInInteractive--------*/
#ifndef LOCAL
#define endl '\n'
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
constexpr int MOD = 1000 * 1000 * 1000 + 7;
constexpr int FFT_MOD = 998244353;
const int P1E6 = 1336337;
const int P1E3 = 1009;
const ll P1E14 = 100000000000031;
const ll P1E17 = 100000000000000003;
const ld PI = acosl(-1.);//3.1415926535897932384626433832795
const ld EPS = 1e-9;
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << "{\"" << _m.begin()->first << "\", \"" << _m.begin()->second << "\"}"; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", { \"" << _it->first << "\", \"" << _it->second << "\"}"; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char * infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif //LOCAL
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif //LOCAL
;

/*-------------------------------------------------ALLOCATOR----------------------------------------------*/
//#define ALLOC_LOCAL
#ifdef ALLOC_LOCAL
const int ML_ = 1000;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false); _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD) { if (pow < 0) { pow = pow % (MD - 1) + MD - 1; } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

int tb[101][101];

inline void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			tb[i][j] = c - '0';
		}
	}

	vector<pair<int, int>> ans;

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			if (tb[i][j] == 1) {
				ans.push_back({ i + 1, j + 1 });
				if (tb[i][j + 1] == 1) ans.push_back({ i + 1, j + 2 });
				else ans.push_back({ i + 2, j + 2 });
				ans.push_back({ i + 2, j + 1 });
				tb[i][j] ^= 1;
				if (tb[i][j + 1] == 1) tb[i][j + 1] ^= 1;
				else tb[i + 1][j + 1] ^= 1;
				tb[i + 1][j] ^= 1;
			} else if (tb[i][j + 1] == 1) {
				ans.push_back({ i + 1, j + 2 });
				ans.push_back({ i + 2, j + 2 });
				ans.push_back({ i + 2, j + 1 });
				tb[i][j + 1] ^= 1;
				tb[i + 1][j + 1] ^= 1;
				tb[i + 1][j] ^= 1;
			}
		}
	}
	
	int i = n - 2;
	for (int j = 0; j < m - 2; ++j) {
		if (tb[i][j] == 1) {
			ans.push_back({ i + 1, j + 1 });
			ans.push_back({ i + 1, j + 2 });
			if (tb[i + 1][j] == 1) ans.push_back({ i + 2, j + 1 });
			else ans.push_back({ i + 2, j + 2 });
			tb[i][j] ^= 1;
			tb[i][j + 1] ^= 1;
			if (tb[i + 1][j] == 1) tb[i + 1][j] ^= 1;
			else tb[i + 1][j + 1] ^= 1;
		} else if (tb[i + 1][j] == 1) {
			ans.push_back({ i + 1, j + 2 });
			ans.push_back({ i + 2, j + 1 });
			ans.push_back({ i + 2, j + 2 });
			tb[i][j + 1] ^= 1;
			tb[i + 1][j] ^= 1;
			tb[i + 1][j + 1] ^= 1;
		}
	}
	int j = m - 2;

	int cnt = tb[i][j] + tb[i][j + 1] + tb[i + 1][j] + tb[i + 1][j + 1];

	while (cnt != 0) {
		if (cnt == 1) {
			int one = 0;
			if (tb[i][j]) {
				one = 0;
			}
			if (tb[i + 1][j]) {
				one = 1;
			}
			if (tb[i][j + 1]) {
				one = 2;
			}
			if (tb[i + 1][j + 1]) {
				one = 3;
			}
			if (one == 3) {
				tb[i][j] ^= 1;
				ans.push_back({ i + 1, j + 1 });
				tb[i + 1][j] ^= 1;
				ans.push_back({ i + 2, j + 1 });
				tb[i + 1][j + 1] ^= 1;
				ans.push_back({ i + 2, j + 2 });
			} else {
				tb[i][j] ^= 1;
				ans.push_back({ i + 1, j + 1 });
				tb[i + 1][j] ^= 1;
				ans.push_back({ i + 2, j + 1 });
				tb[i][j + 1] ^= 1;
				ans.push_back({ i + 1, j + 2 });
			}
		} else if (cnt == 2) {
			int one = 0;
			if (tb[i][j]) {
				one = 0;
			}
			if (tb[i + 1][j]) {
				one = 1;
			}
			if (tb[i][j + 1]) {
				one = 2;
			}
			if (tb[i + 1][j + 1]) {
				one = 3;
			}
			if (!tb[i][j]) {
				tb[i][j] ^= 1;
				ans.push_back({ i + 1, j + 1 });
			}
			if (!tb[i + 1][j]) {
				tb[i + 1][j] ^= 1;
				ans.push_back({ i + 2, j + 1 });
			}
			if (!tb[i][j + 1]) {
				tb[i][j + 1] ^= 1;
				ans.push_back({ i + 1, j + 2 });
			}
			if (!tb[i + 1][j + 1]) {
				tb[i + 1][j + 1] ^= 1;
				ans.push_back({ i + 2, j + 2 });
			}
			if (one == 0) {
				tb[i][j] ^= 1;
				ans.push_back({ i + 1, j + 1 });
			} else if (one == 1) {
				tb[i + 1][j] ^= 1;
				ans.push_back({ i + 2, j + 1 });
			} else if (one == 2) {
				tb[i][j + 1] ^= 1;
				ans.push_back({ i + 1, j + 2 });
			} else {
				tb[i + 1][j + 1] ^= 1;
				ans.push_back({ i + 2, j + 2 });
			}
		} else if (cnt == 3) {
			if (tb[i][j]) {
				tb[i][j] ^= 1;
				ans.push_back({ i + 1, j + 1 });
			}
			if (tb[i + 1][j]) {
				tb[i + 1][j] ^= 1;
				ans.push_back({ i + 2, j + 1 });
			}
			if (tb[i][j + 1]) {
				tb[i][j + 1] ^= 1;
				ans.push_back({ i + 1, j + 2 });
			}
			if (tb[i + 1][j + 1]) {
				tb[i + 1][j + 1] ^= 1;
				ans.push_back({ i + 2, j + 2 });
			}
		} else {
			if (tb[i][j]) {
				tb[i][j] ^= 1;
				ans.push_back({ i + 1, j + 1 });
			}
			if (tb[i + 1][j]) {
				tb[i + 1][j] ^= 1;
				ans.push_back({ i + 2, j + 1 });
			}
			if (tb[i][j + 1]) {
				tb[i][j + 1] ^= 1;
				ans.push_back({ i + 1, j + 2 });
			}
		}
		cnt = tb[i][j] + tb[i][j + 1] + tb[i + 1][j] + tb[i + 1][j + 1];
	}
	assert(sz(ans) % 3 == 0);
	assert(sz(ans) / 3 <= n * m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			assert(tb[i][j] == 0);
		}
	}
	cout << sz(ans) / 3 << endl;
	for (int i = 0; i < sz(ans); i += 3) {
		cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << endl;
	}
}

signed main() {

	if (*infile != '\0')
		assert(freopen(infile, "r", stdin));
	if (*outfile != '\0')
		assert(freopen(outfile, "w", stdout));

	speedup;
	coutdouble;


	int tst = 1;
	cin >> tst;
	while (tst-- > 0) {
		solve();
	}

#ifdef LOCAL
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL

	return 0;
}