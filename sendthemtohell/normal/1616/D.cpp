#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,tune=native")
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
//#include <x86intrin.h> // uncomment for some sse magic

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
//mt19937 rd((uint)chrono::steady_clock::now().time_since_epoch().count());
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
/*---------------------------------------------------------------------------------------------------------*/
#ifdef LOCAL
#undef assert
#define assert(ok) if(!(ok)) throw;  
#endif // LOCAL
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream& operator << (ostream& _out, const pair<T, U>& _p) { _out << _p.first << " " << _p.second; return _out; }
template<typename T, typename U> inline istream& operator >> (istream& _in, pair<T, U>& _p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream& operator << (ostream& _out, const vector<T>& _v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline istream& operator >> (istream& _in, vector<T>& _v) { for (auto& _i : _v) _in >> _i; return _in; }
template<typename T> inline ostream& operator << (ostream& _out, const set<T>& _s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream& operator << (ostream& _out, const multiset<T>& _s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream& operator << (ostream& _out, const unordered_set<T>& _s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T> inline ostream& operator << (ostream& _out, const unordered_multiset<T>& _s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; }
template<typename T, typename U> inline ostream& operator << (ostream& _out, const map<T, U>& _m) { if (_m.empty()) return _out; _out << "{\"" << _m.begin()->first << "\", \"" << _m.begin()->second << "\"}"; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", { \"" << _it->first << "\", \"" << _it->second << "\"}"; return _out; }
template<typename T, typename U> inline ostream& operator << (ostream& _out, const unordered_map<T, U>& _m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; }
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char* infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif //LOCAL
;
const char* outfile =
#ifdef LOCAL
""
#else
""
#endif //LOCAL
;

/*-------------------------------------------------ALLOCATOR----------------------------------------------*/
//#define ALLOC_LOCAL
#ifdef ALLOC_LOCAL
const int ML_ = 500;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void* operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void*) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD) { if (pow < 0) { pow = pow % (ll(MD) - 1) + MD - 1; } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
inline ll gcdex(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod) { return pwm(r % _mod, ll(_mod) - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

const int N = 50 * 1000 + 57;
int t[4 * N];

void build(int v, int l, int r) {
	if (r - l == 1) {
		t[v] = l;
		return;
	}
	build(v << 1, l, (l + r) / 2);
	build(v << 1 | 1, (l + r) / 2, r);

	t[v] = INF;
}

void push_t(int v, int l, int r) {
	if (r - l == 1) return;
	t[v << 1] = min(t[v], t[v << 1]);
	t[v << 1 | 1] = min(t[v], t[v << 1 | 1]);
	t[v] = INF;
	return;
}

int get_t(int v, int l, int r, int at) {
	push_t(v, l, r);
	if (l > at || r <= at) {
		return INF;
	}
	if (r - l == 1) {
		return t[v];
	}
	return min(get_t(v << 1, l, (l + r) / 2, at), get_t(v << 1 | 1, (l + r) / 2, r, at));
}

void set_t(int v, int l, int r, int L, int R, int V) {
	push_t(v, l, r);
	if (R <= l || r <= L) {
		return;
	}
	if (L <= l && r <= R) {
		t[v] = min(t[v], V);
		push_t(v, l, r);
		return;
	}
	set_t(v << 1, l, (l + r) / 2, L, R, V);
	set_t(v << 1 | 1, (l + r) / 2, r, L, R, V);
}

struct Data {
	ll pf, sf, seg, sum;

	template<typename T>
	Data(T vl) : pf(vl), sf(vl), seg(0), sum(vl) {}

	Data(ll a, ll b, ll c, ll d) : pf(a), sf(b), seg(c), sum(d) {}

	Data() : pf(0), sf(0), seg(0), sum(0) {}

	Data operator+(const Data& oth) {
		ll p = min(pf, sum + oth.pf);
		ll s = min(oth.sf, oth.sum + sf);
		ll sg = min({ sf + oth.pf, seg, oth.seg });
		ll sm = sum + oth.sum;

		return Data(p, s, sg, sm);
	}
};

Data tt[4 * N];

void build2(int v, int l, int r, const vector<ll>& a) {
	if (r - l == 1) {
		tt[v] = Data(a[l]);
		return;
	}
	build2(v << 1, l, (l + r) >> 1, a);
	build2(v << 1 | 1, (l + r) >> 1, r, a);
	tt[v] = tt[v << 1] + tt[v << 1 | 1];
}

Data get2(int v, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return tt[v];
	}
	if (L >= (l + r) / 2) {
		return get2(v << 1 | 1, (l + r) / 2, r, L, R);
	} 
	if (R <= (l + r) / 2) {
		return get2(v << 1, l, (l + r) / 2, L, R);
	}
	auto a = get2(v << 1, l, (l + r) / 2, L, R);
	auto b = get2(v << 1 | 1, (l + r) / 2, r, L, R);
	return a + b;
}

inline void solve() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> v(n);
		cin >> v;
		int x;
		cin >> x;

		for (auto& i : v) {
			i -= x;
		}
		v.push_back(-LLINF);
		++n;
		build(1, 0, n + 1);
		/*
		vector<ll> ps(sz(v) + 1);
		vector<pair<int, ll>> psm = { {0, 0} };
		vector<int> ids(sz(v), n + 1);
		for (int i = 1; i <= sz(v); ++i) {
			ps[i] = ps[i - 1] + v[i - 1];
			if (i >= 2 && v[i - 1] + v[i - 2] < 0) {
				
			}
		}*/
		build2(1, 0, n, v);
		for (int i = 0; i < n; ++i) {
			int cur = get_t(1, 0, n + 1, i);
			int l = i;
			int r = n + 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (get2(1, 0, n, i, m).seg < 0) {
					r = m;
				}
				else {
					l = m;
				}
			}
			//cerr << i << " -> " << cur << " " << r << endl;
			set_t(1, 0, n + 1, i + 2, i + 3, cur + 1);
			set_t(1, 0, n + 1, i + 1, r + 1, cur + 1);
		}
		cout << n - get_t(1, 0, n + 1, n) << endl;
	}
}

signed main() {

	if (*infile != '\0') {
		assert(freopen(infile, "r", stdin));
	}
	if (*outfile != '\0') {
		assert(freopen(outfile, "w", stdout));
	}

	speedup;
	coutdouble;


	//int tst = 1;
	//cin >> tst;
	//while (tst-- > 0) {
	solve();
	//}

#ifdef LOCAL
	cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
	//while (true);
#endif // LOCAL

	return 0;
}