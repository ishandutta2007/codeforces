#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif //LOCAL

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#define push_back pb
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


#ifdef LOCAL
//#include <vld.h>
#endif //LOCAL
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed

#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()

/*------CommentInInteractive--------*/
#ifndef LOCAL
//#define endl "\n"
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const int MOD = 1000 * 1000 * 1000LL + 7;
const ll FFT_MOD = 998244353;
//const int RMOD = MOD - 2;
const int P1M = 1336337; //Large prime ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld EPS = 1e-14;
const ld PI = acos(-1.);//3.1415926535897932384626433832795;
						/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; }
template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
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
const int ML_ = 950;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*----------------------------------------------------MATHS------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll pwm(ll xx, ll pow, ll MD = MOD) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MD; mlt %= MD; } else { pow >>= 1; xx *= xx; xx %= MD; } }return mlt; }
inline ll inv(ll r, ll _mod = MOD) { return pwm(r % _mod, _mod - 2, _mod); }
/*--------------------------------------------------------------------------------------------------------*/

const int N = 557 * 557 + 57;

vector<int> g[N];
int in_deg[N];
int used[N];

int hsh(pair<int, int> p) {
	return p.x * 500 + p.y;
}

void bfs1() {
	vector<int> q;
	q.pb(0);
	memset(used, -1, sizeof used);
	used[0] = 0;
	int ptr = 0;
	while (ptr != sz(q)) {
		int u = q[ptr++];
		for (auto v : g[u]) {
			if (used[v] == -1) {
				//win[v] = true;
				used[v] = used[u] + 1;
				q.pb(v);
			}
		}
	}
}

inline void solve() {
	int h, t, r;
	cin >> h >> t >> r;
	int s = hsh({ h, t });
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y;
		cin >> x >> y;
		
		for (int hh = x; hh <= r; ++hh) {
			for (int tt = y; tt + hh <= r; ++tt) {
				int nh = hh - x + i;
				int nt = tt - y;
				g[hsh({ hh, tt })].pb(hsh({ nh, nt }));
				++in_deg[hsh({ nh, nt })];
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;

		for (int hh = x; hh <= r; ++hh) {
			for (int tt = y; tt + hh <= r; ++tt) {
				int nh = hh - x;
				int nt = tt - y + i;
				g[hsh({ hh, tt })].pb(hsh({ nh, nt }));
				++in_deg[hsh({ nh, nt })];
			}
		}
	}

	bfs1();
	if (used[hsh({ h, t })] != -1) {
		cout << "Ivan\n";
		cout << used[hsh({ h, t })] << endl;
		return;
	}
	vector<int> q;
	int ptr = 0;
	for (int i = 0; i < N; ++i) {
		if (in_deg[i] == 0) {
			q.pb(i);
			used[i] = 1;
		}
	}
	while (ptr != sz(q)) {
		int u = q[ptr++];
		for (auto v : g[u]) {
			if (used[v] == -1) {
				--in_deg[v];
				if (in_deg[v] == 0) {
					used[v] = used[u] + 1;
					q.pb(v);
				}
			}
		}
	}
	if (used[hsh({ h, t })] != -1) {
		cout << "Zmey\n";
		cout << used[hsh({ h, t })] << endl;
		return;
	}
	cout << "Draw\n";
}



int main() {

	if (*infile != '\0')
		(void)freopen(infile, "r", stdin);
	if (*outfile != '\0')
		(void)freopen(outfile, "w", stdout);

	speedup;
	coutdouble;


	//int tst = 100;
	//srand(time(NULL));
	//cin >> tst;
	//scanf("%d", &tst);
	//while (tst-- > 0) {
	//while(true) {
	solve();
	//if ((tst & 0xF) == 0) {
	//cout << "ok\n";
	//}
	//cout << "/*-----------------*/\n";
	//}

#ifdef LOCAL
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL

	return 0;
}