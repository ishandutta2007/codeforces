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
//#define endl "\n"
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 100 + 10;
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
inline ll inv(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

int fld[N][N];
pair<int, int> mv[] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
pair<int, int> end_ = { -1, -1 };
char p_mv[] = { 'D', 'R', 'U', 'L' };
bool ch[] = { 0, 0 };
vector<int> go;
bool used[N][N];
int n, m;

inline pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return mp(a.x + b.x, a.y + b.y);
}

pair<int, int> ask(int k) {
	cout << p_mv[k] << endl;
	pair<int, int> kek;
	cin >> kek;
	if (kek + mp(-1, -1) == end_)
		exit(0);
	return{ kek.x - 1, kek.y - 1 };
}

bool good(pair<int, int> a) {
	return a.x < n && a.x >= 0 && a.y < m && a.y >= 0 && !used[a.x][a.y] && fld[a.x][a.y];
}

bool dfs(pair<int, int> cur) {
	used[cur.x][cur.y] = true;
	if (cur == end_)
		return true;
	for (int i = 0; i < 4; ++i) {
		auto nxt = cur + mv[i];
		if (good(nxt)) {
			go.pb(i);
			if (dfs(nxt))
				return true;
			go.pop_back();
		}
	}
	return false;
}

inline void solve(ld tt) {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '*') {
				fld[i][j] = 0;
			}
			else if (s[j] == '.') {
				fld[i][j] = 1;
			}
			else {
				assert(s[j] == 'F');
				fld[i][j] = 1;
				end_ = { i, j };
			}
		}
	}
	//for (int i = 0; i < n; ++i) {
	//	for (int j = 0; j < m; ++j) {
	//		cout << fld[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	pair<int, int> cp = { 0, 0 };
	if (fld[1][0]) {
		cp = ask(0);
		if (cp == mp(0, 0)) {
			swap(p_mv[0], p_mv[2]);
		}
		else {
			cp = ask(2);
		}
		while (cp != end_ && !fld[cp.x][cp.y + 1]) {
			cp = ask(0);
		}
		if (cp == end_)
			return;
		auto np = ask(1);
		if (np == cp) {
			swap(p_mv[1], p_mv[3]);
		}
		cp = np;
		if (cp == end_)
			return;
		//cout << cp << endl;
		dfs(cp);
		//cout << go << endl;
		//return;
		for (auto &i : go) {
			cout << p_mv[i] << endl;
			cin >> cp;
		}
	}
	else if (fld[0][1]) {
		cp = ask(1);
		if (cp == mp(0, 0)) {
			swap(p_mv[1], p_mv[3]);
		}
		else {
			cp = ask(3);
		}
		while (cp != end_ && !fld[cp.x + 1][cp.y]) {
			cp = ask(1);
		}
		if (cp == end_)
			return;
		auto np = ask(0);
		if (np == cp) {
			swap(p_mv[0], p_mv[2]);
		}
		cp = np;
		if (cp == end_)
			return;
		dfs(cp);
		//cout << go << endl;
		//return;
		for (auto &i : go) {
			cout << p_mv[i] << endl;
			cin >> cp;
		}
	}
	
}

int main() {
	ld tt = clock();

	if (*infile != '\0')
		freopen(infile, "r", stdin);
	if (*outfile != '\0')
		freopen(outfile, "w", stdout);

	//speedup;
	coutdouble;

	//while(true)
	solve(tt);

#ifdef LOCAL
	cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL
	return 0;
}