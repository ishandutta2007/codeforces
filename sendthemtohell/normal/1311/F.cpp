#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")
#endif //LOCAL

#define _SCL_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:256000000")

//#define push_back pb
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
typedef long double ld;

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
constexpr uint MOD = 1000 * 1000 * 1000 + 7;
constexpr uint FFT_MOD = 998244353;
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
const int ML_ = 450;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD) { if (pow < 0) { pow = pow % (MD - 1) + MD - 1; } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod) { return pwm(r % _mod, _mod - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

const int N = 200 * 1000 + 57;
pair<int, ll> tl[4 * N];
pair<int, ll> tr[4 * N];


void add_t(pair<int, ll>* t, int v, int l, int r, int pos, pair<int, ll> vl) {
	if (l > pos || r <= pos) {
		return;
	}
	if (r - l == 1) {
		t[v].x += vl.x;
		t[v].y += vl.y;
		return;
	}

	add_t(t, v << 1, l, (l + r) >> 1, pos, vl);
	add_t(t, v << 1 | 1, (l + r) >> 1, r, pos, vl);
	t[v].x = t[v << 1].x + t[v << 1 | 1].x;
	t[v].y = t[v << 1].y + t[v << 1 | 1].y;
};

pair<int, ll> get_t (pair<int, ll>* t, int v, int l, int r, int lq, int rq) {
	if (lq >= r || rq <= l) {
		return{ 0, 0 };
	}
	if (lq <= l && r <= rq) {
		return t[v];
	}
	auto p1 = get_t(t, v << 1, l, (l + r) >> 1, lq, rq);
	auto p2 = get_t(t, v << 1 | 1, (l + r) >> 1, r, lq, rq);
	return{ p1.x + p2.x, p1.y + p2.y };
};

inline void solve() {
	int n = 4;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x;
		//v[i].x = rd() % 10;
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i].y;
		//v[i].y = rd() % 10;
	}
	sort(all(v));

#ifdef LOCAL
	memset(tl, 0, sizeof tl);
	memset(tr, 0, sizeof tr);

	ll stp = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (v[i].y > v[j].y) {
			
			} else {
				stp += v[j].x - v[i].x;
			}
		}
	}
#endif


	ll ans = 0;
	ll golft = 0;
	ll cntlft = 0;

	vector<int> crl, crr;
	vector<int> gol, gor;
	for (int i = 0; i < n; ++i) {
		if (v[i].y < 0) {
			gol.push_back(-v[i].y);
			crl.push_back(v[i].x);
			++cntlft;
			golft += v[i].x;
		} else {
			gor.push_back(v[i].y);
			crr.push_back(v[i].x);
			ans += cntlft * v[i].x - golft;
		}
	}

	vector<int> cl = gol, cr = gor;
	sort(all(cl));
	sort(all(cr));
	for (int i = 0; i < sz(gol); ++i) {
		gol[i] = lower_bound(all(cl), gol[i]) - cl.begin();
	}
	for (int i = 0; i < sz(gor); ++i) {
		gor[i] = lower_bound(all(cr), gor[i]) - cr.begin();
	}

	for (int i = 0; i < sz(gol); ++i) {
		auto p = get_t(tl, 1, 0, N, gol[i], N);
		ans += ll(p.x) * crl[i] - p.y;
		add_t(tl, 1, 0, N, gol[i], { 1, crl[i] });
	}
	reverse(all(gor));
	reverse(all(crr));
	for (int i = 0; i < sz(gor); ++i) {
		auto p = get_t(tr, 1, 0, N, gor[i], N);
		ans += abs(ll(p.x) * crr[i] - p.y);
		add_t(tr, 1, 0, N, gor[i], { 1, crr[i] });
	}
	cout << ans << endl;

#ifdef LOCAL
	if (ans != stp) {
		for (auto &p : v) {
			cout << p << endl;
		}
	}
#endif // LOCAL

}

int main() {

	if (*infile != '\0')
		(void)freopen(infile, "r", stdin);
	if (*outfile != '\0')
		(void)freopen(outfile, "w", stdout);

	speedup;
	coutdouble;


	//int tst = 1;
	//srand(time(NULL));
	//cin >> tst;
	//scanf("%d", &tst);
	//while (tst-- > 0) {
	//while (true) {
	solve();
	//if ((tst & 0xF) == 0) {
	//cerr << "ok\n";
	//}
	//cerr << "/*-----------------*/\n";
	//}

#ifdef LOCAL
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL

	return 0;
}