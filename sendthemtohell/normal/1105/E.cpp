#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif //LOCAL

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

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

/*------CommentInInteractive--------*/
#ifndef LOCAL
#define endl '\n'
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const int MOD = 1000 * 1000 * 1000 + 7;
const ll FFT_MOD = 998244353;
const int P1M = 1336337; //Large prime ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld EPS = 1e-7;
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
const int ML_ = 200;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD = MOD) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
inline int inv(ll r, int _mod = MOD) { return pwm(r % _mod, _mod - 2, _mod); }
inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; }ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline ll gcdexm(ll a, ll b, ll &x, ll &y, ll p) { if (b == 0) { x = 1; y = 0; return a; }ll xx, yy; ll gc = gcdexm(b, a % b, yy, xx, p); x = xx; y = ((yy - (a / b) * xx) % p + p) % p; return gc; } //returns x = inv(a) mod p, p being not prime. returns gcd(x, p)
/*-----------------------------------------------------CODE------------------------------------------------*/

const int N = 45;

ll g[N];
int par[N];
int rk[N];
bool used[1 << (N / 2)];
bool is_cl[1 << (N / 2)];
int mx_cl[1 << (N / 2)];


int find(int v)	{
	if (v == par[v]) {
		return v;
	}
	return par[v] = find(par[v]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;

	if (rk[a] < rk[b]) swap(a, b);

	par[b] = a;

	if (rk[a] == rk[b]) {
		++rk[a];
	}
}

void init(int n) {
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		rk[i] = 0;
	}
}


void go1(ll msk, int n) {
	is_cl[msk] = true;
	for (int i = 0; i < n; ++i) {
		ll nmsk = (msk | (1LL << i));
		if (nmsk != msk) {
			if ((msk & g[i]) == msk && !is_cl[nmsk]) {
				go1(nmsk, n);
			}
		}
	}
}

int go2(ll msk, int n, int cnt) {
	if (mx_cl[msk]) {
		return mx_cl[msk];
	}

	if (is_cl[msk]) {
		mx_cl[msk] = cnt;
	}

	for (int i = 0; i < n; ++i) {
		ll nmsk = (msk & ~(1LL << i));
		if (nmsk != msk) {
			mx_cl[msk] = max(mx_cl[msk], go2(nmsk, n, cnt - 1));
		}
	}

	return mx_cl[msk];
}


int go3(ll msk, int low, int hig, int sz = 0) {
	int ans = 0;
	int ok_m = 0;
	used[msk >> low] = true;
	for (int i = 0; i < low; ++i) {
		if ((msk & g[i]) == msk) {
			ok_m |= (1 << i);
		}
	}

	ans = sz + mx_cl[ok_m];

	for (int i = low; i < hig; ++i) {
		ll nmsk = (msk | (1LL << i));
		if (nmsk != msk) {
			if ((msk & g[i]) == msk && !used[nmsk >> low]) {
				ans = max(ans , go3(nmsk, low, hig, sz + 1));
			}
		}
	}
	return ans;
}


inline void solve() {
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, string>> v(n);
	set<string> coord;
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x;
		if (v[i].x == 2) {
			cin >> v[i].y;
			coord.insert(v[i].y);
		}
	}

	for (int i = 0; i < m; ++i) {
		g[i] = (1LL << m) - 1 - (1LL << i);
	}

	vector<string> cr(all(coord));

	vector<pair<int, int>> norm;
	for (auto &p : v) {
		if (p.x == 2) {
			norm.push_back({ 2, (int)(lower_bound(all(cr), p.y) - cr.begin()) });
		}
		else {
			norm.push_back({ 1, -1 });
		}
	}
	norm.push_back({ 1,-1 });


	init(m);
	for (int i = 1; i < n + 1; ++i) {
		if (norm[i].x == 1) {
			for (int i = 0; i < m; ++i) {
				for (int j = i + 1; j < m; ++j) {
					if (find(i) == find(j)) {
						g[i] &= ~(1LL << j);
						g[j] &= ~(1LL << i);
					}
				}
			}

			init(m);
		}
		else if(norm[i - 1].x != 1){
			unite(norm[i].y, norm[i - 1].y);
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (g[i] & (1LL << j)) {
				//cerr << "! " << i << " " << j << endl;
			}
		}
	}

	int hlf = m / 2;
	go1(0, hlf);
	cerr << "OK1\n";
	go2((1 << hlf) - 1, hlf, hlf);
	cerr << "OK2\n";
	cout << go3(0, hlf, m) << endl;
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