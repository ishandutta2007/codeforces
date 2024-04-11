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
const int INF = 1000 * 1000 * 1000;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 2 * 100 * 1000 + 322;
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
#endif
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif
;
/*----------------------------------------------------MATHS------------------------------------------------*/
inline int gcd(int a, int b) { while (b) { int tmp = a%b; a = b; b = tmp; } return a; }
inline int gcd(vector<int> a) { while (a.size() > 1) { int tmp1 = a.back(), tmp2 = a.back(); a.pop_back(), a.pop_back(); a.push_back(gcd(tmp1, tmp2)); } return a[0]; }
inline ll lcm(int a, int b) { return (ll)a*(ll)b / gcd(a, b); }
inline ll pwm(ll xx, ll pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MOD; mlt %= MOD; } else { pow >>= 1; xx *= xx; xx %= MOD; } }return mlt; }
inline ll pw(ll xx, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; } else { pow >>= 1; xx *= xx; } }return mlt; }
inline ll rev(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

inline void solve(ld tt) {
	int n, mb = 0, cb = 0, ht = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '[') {
			++cb;
		}
		else {
			--cb;
		}
		assert(cb >= 0);
		mb = max(mb, cb);
	}
	assert(cb == 0);
	vector<pair<int, int>> ch(101);
	vector<bool> gd(101);
	cb = 0;
	ht = 2 * (mb - 1) + 3;
	ch[0] = mp(0,ht -1);
	for (int i = 1; i < n; ++i) {
		int ct;
		if (s[i] == ']' && s[i - 1] == '[') {
			gd[i - 1] = true;
			gd[i] = true;
		}
		if (s[i] == s[i - 1]) {
			if (s[i] == '[') {
				ch[i] = mp(ch[i - 1].x + 1, ch[i - 1].y - 1);
			}
			else {
				ch[i] = mp(ch[i - 1].x - 1, ch[i - 1].y + 1);
			}
		}
		else {
			ch[i] = mp(ch[i - 1].x, ch[i - 1].y);
		}
	}
	for (int i = 0; i < ht; ++i) {
		for (int j = 0; j < n; ++j) {
			if (gd[j]) {
				if (s[j] == '[') {
					if (ch[j].x < i && ch[j].y > i) {
						cout << "|  ";
					}
					else if (ch[j].x == i || ch[j].y == i) {
						cout << "+- ";
					}
					else if (j > 0 && (ch[j - 1].x == i || ch[j - 1].y == i) && s[j - 1] == '[') {
						cout << "-  ";
					}
					else {
						cout << "   ";
					}
				}
				else {
					if (ch[j].x < i && ch[j].y > i) {
						cout << " |";
					}
					else if (ch[j].x == i || ch[j].y == i) {
						cout << "-+";
					}
					else if (j < n - 1 && (ch[j + 1].x == i || ch[j + 1].y == i) && s[j + 1] == ']') {
						cout << " -";
					}
					else {
						cout << "  ";
					}
				}
			}
			else {
				if (s[j] == '[') {
					if (ch[j].x < i && ch[j].y > i) {
						cout << "|";
					}
					else if (ch[j].x == i || ch[j].y == i) {
						cout << "+";
					}
					else if (j > 0 && (ch[j - 1].x == i || ch[j - 1].y == i) && s[j - 1] == '[') {
						cout << "-";
					}
					else {
						cout << " ";
					}
				}
				else {
					if (ch[j].x < i && ch[j].y > i) {
						cout << "|";
					}
					else if (ch[j].x == i || ch[j].y == i) {
						cout << "+";
					}
					else if (j < n - 1 && (ch[j + 1].x == i || ch[j + 1].y == i) && s[j + 1] == ']')  {
						cout << "-";
					}
					else {
						cout << " ";
					}
				}
			}
		}
		cout << endl;
	}
}

int main() {
	ld tt = clock();
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);

	speedup;
	coutdouble;

	//while(true)
		solve(tt);

#ifdef LOCAL
	cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL
	return 0;
}