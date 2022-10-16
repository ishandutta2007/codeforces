#pragma GCC optimize("O3")

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

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
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed

#define all(v) (v).begin(),(v).end()
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int INF = 2 * 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 100 + 4;
const int P1M = 1336337; //Large prime ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/
template<typename T, typename U> inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
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
/*----------------------------------------------------MATHS------------------------------------------------*/
inline int gcd(int a, int b) { while (b) { int tmp = a%b; a = b; b = tmp; } return a; }
inline ll lcm(int a, int b) { return (ll)a*(ll)b / gcd(a, b); }
inline ll pwm(ll xx, ll pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MOD; mlt %= MOD; } else { pow >>= 1; xx *= xx; xx %= MOD; } }return mlt; }
inline ll pw(ll xx, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; } else { pow >>= 1; xx *= xx; } }return mlt; }
inline ll rev(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

inline ll val(ll a, ll b) {
	if (2 * a > b)
		return 500;
	if (4 * a > b)
		return 1000;
	if (8 * a > b)
		return 1500;
	if (16 * a > b)
		return 2000;
	if (32 * a > b)
		return 2500;
	return 3000;
}

inline ll pts(vector<ll> tm, vector<ll> sc, int n) {
	ll res = 0;
	for (int i = 0; i < 5; ++i) {
		if (tm[i] != -1)
			res += val(sc[i], n) - tm[i] * val(sc[i], n) / 250;
	}
	return res;
}

inline void solve(ld tt) {
	int n;
	int a1, a2, a3, a4, a5;
	int b1, b2, b3, b4, b5;
	int s1, s2, s3, s4, s5;
	cin >> n;
	cin >> a1 >> a2 >> a3 >> a4 >> a5;
	cin >> b1 >> b2 >> b3 >> b4 >> b5;
	s1 = (a1 != -1);
	s2 = (a2 != -1);
	s3 = (a3 != -1);
	s4 = (a4 != -1);
	s5 = (a5 != -1);
	s1 += (b1 != -1);
	s2 += (b2 != -1);
	s3 += (b3 != -1);
	s4 += (b4 != -1);
	s5 += (b5 != -1);
	for (int i = 2; i < n; ++i) {
		vector<int> tmp(5);
		cin >> tmp;
		s1 += (tmp[0] != -1);
		s2 += (tmp[1] != -1);
		s3 += (tmp[2] != -1);
		s4 += (tmp[3] != -1);
		s5 += (tmp[4] != -1);
	}
	for(int m = 0; m < 1e6; ++m) {
		ll s1n, s2n, s3n, s4n, s5n;
		if (a1 != -1 && b1 == -1) {
			s1n = s1;
		}
		else if (a1 == -1 && b1 != -1) {
			s1n = s1;
		}
		else if (a1 < b1) {
			s1n = s1;
		}
		else {
			s1n = s1 + m;
		}
		if (a2 != -1 && b2 == -1) {
			s2n = s2;
		}
		else if (a2 == -1 && b2 != -1) {
			s2n = s2;
		}
		else if (a2 < b2) {
			s2n = s2;
		}
		else {
			s2n = s2 + m;
		}


		if (a3 != -1 && b3 == -1) {
			s3n = s3;
		}
		else if (a3 == -1 && b3 != -1) {
			s3n = s3;
		}
		else if (a3 < b3) {
			s3n = s3;
		}
		else {
			s3n = s3 + m;
		}
		if (a4 != -1 && b4 == -1) {
			s4n = s4;
		}
		else if (a4 == -1 && b4 != -1) {
			s4n = s4;
		}
		else if (a4 < b4) {
			s4n = s4;
		}
		else {
			s4n = s4 + m;
		}


		if (a5 != -1 && b5 == -1) {
			s5n = s5;
		}
		else if (a5 == -1 && b5 != -1) {
			s5n = s5;
		}
		else if (a5 < b5) {
			s5n = s5;
		}
		else {
			s5n = s5 + m;
		}

		if (pts({ a1,a2,a3,a4,a5 }, { s1n,s2n,s3n,s4n,s5n }, n + m) > pts({ b1,b2,b3,b4,b5 }, { s1n,s2n,s3n,s4n,s5n }, n + m)) {
			cout << m << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
	ld tt = clock();

	if (*infile != '\0')
		freopen(infile, "r", stdin);
	if (*outfile != '\0')
		freopen(outfile, "w", stdout);

	speedup;
	//coutdouble;

	//while(true)
	solve(tt);

#ifdef LOCAL
	cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL
	return 0;
}