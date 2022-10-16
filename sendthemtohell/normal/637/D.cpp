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
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 200*1000 + 10;
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

vector<pair<int, int>> G[N];
vector<int> cl[N];
int m_deg = 0;

void dfs(int v, int pr, int bn) {
	int clr = 0;
	for (auto &i : G[v]) {
		if(clr == bn)
			++clr;
		if (i.x == pr)
			continue;
		cl[clr].pb(i.y);
		dfs(i.x, v, clr);
		++clr;
	}
	m_deg = max(m_deg, clr);
}

inline void solve(ld tt) {
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	vector<int> obst(n);
	cin >> obst;
	sort(all(obst));
	//cout << obst << endl;
	int cur_ps = obst[0] - 1, nxt_obst = 0;
	vector<pair<bool, int>> ans;
	if(cur_ps > 0)
		ans.pb({ false, cur_ps });
	//cout << "RUN " << cur_ps << endl;
	if (cur_ps < s) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	while (nxt_obst != n) {
		if (obst[n - 1] + 1 - cur_ps <= d) {
			ans.pb({ true, obst[n - 1] + 1 - cur_ps });
			if(m - obst[n - 1] - 1 > 0)
			ans.pb({ false, m - obst[n - 1] - 1 });
			break;
		}
		int jmp = 2;
		while (jmp <= d && obst[nxt_obst + 1] - obst[nxt_obst] - 2 < s) {
			//cout << "lol\n";
			++nxt_obst;
			jmp = obst[nxt_obst] + 1 - cur_ps;
		}
		if (jmp > d) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		++nxt_obst;
		ans.pb({ true,jmp });
		cur_ps += jmp;
		if(obst[nxt_obst] - cur_ps - 1 > 0)
		ans.pb({ false,obst[nxt_obst] - cur_ps - 1 });
		cur_ps = obst[nxt_obst] - 1;
	}
	for (auto &i : ans) {
		if (i.x) {
			cout << "JUMP " << i.y << endl;
		}
		else {
			cout << "RUN " << i.y << endl;
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