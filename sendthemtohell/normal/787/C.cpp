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
const int N = 14 * 1000 + 322;
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

short g[N][N>>1];
short sz[N];
short deg[N];
bool used[N];
char res[N];

void dfs(short v, bool ls) {
	used[v] = true;
	if (ls) {
		res[v] = 1;
	}
	else {
		res[v] = 2;
	}
	for (int i=0; i<sz[v]; ++ i) {
	//for (auto u : g[v]) {
		if (!used[g[v][i]]) {
			if (ls) {
				dfs(g[v][i], false);
			}
			else {
				--deg[g[v][i]];
				if (!deg[g[v][i]]) {
					dfs(g[v][i], true);
				}
			}
		}
	}
}

inline void solve(ld tt) {
	short n;
	cin >> n;
	//n = 7000;
	short k1;
	cin >> k1;
	//k1 = 7000;
	vector<short> vk1(k1);
	cin >> vk1;
	//for(int i=0;i<k1;++i){ vk1[i] = rand()%(n-1) + 1; }
	short k2;
	cin >> k2;
	//k2=7000;
	vector<short> vk2(k2);
	//for(int i=0;i<k2;++i){ vk2[i] = rand()%(n-1) + 1; }
	cin >> vk2;
	for (int i = 0; i < n; ++i) {
		for (auto u : vk1)
			g[(((i + u) % n) << 1) | 1][sz[(((i + u) % n) << 1) | 1]++] = i << 1;
			//g[(((i + u) % n) << 1) | 1].pb(i << 1);
		for (auto u : vk2)
			g[((i + u) % n) << 1][sz[((i + u) % n) << 1]++] = (i << 1) | 1;
			//g[((i + u) % n) << 1].pb((i << 1) | 1);
	}
	for (int i = 0; i < 2 * n; i += 2) {
		deg[i] = k1;
		deg[i + 1] = k2;
	}
	used[0] = used[1] = true;
	dfs(0, true);
	dfs(1, true);
	for (int i = 2; i < 2 * n; i+=2) {
		switch (res[i]) {
		case 0:
			cout << "Loop ";
			break;
		case 1:
			cout << "Lose ";
			break;
		case 2:
			cout << "Win ";
		}
	}
	cout << endl;
	for (int i = 3; i < 2 * n; i += 2) {
		switch (res[i]) {
		case 0:
			cout << "Loop ";
			break;
		case 1:
			cout << "Lose ";
			break;
		case 2:
			cout << "Win ";
		}
	}
	cout << endl;
}

int main() {
	ld tt = clock();
	if(*infile != '\0')
	freopen(infile, "r", stdin);
	if(*outfile != '\0')
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