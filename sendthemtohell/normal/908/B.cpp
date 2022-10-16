#ifndef LOCAL 
#pragma GCC optimize("Ofast") 
#endif 
#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 
#define push_back pb 
#define make_pair mp 
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
#ifdef LOCAL 
//#include <vld.h> 
#endif //LOCAL 
using namespace std; 
typedef long long ll; 
typedef long double ld; 
#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false)
#define coutdouble cout<<setprecision(20);cout<<fixed 
#define all(v) (v).begin(),(v).end() 
#define sz(v) (int)(v).size() 
/*------CommentInInteractive--------*/ 
/*	#ifndef LOCAL 
/*#define endl "\n" 
/*#endif //LOCAL 
/*----------------------------------*/ 
const int INF = 1000 * 1000 * 1000 + 322; 
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57; 
const ll MOD = 1000 * 1000 * 1000 + 7; 
const int RMOD = MOD - 2; 
const int N = 100 * 1000 + 57; 
const int P1M = 1336337; //Large prime ( ~1M ) 
const int P1K = 1009; //Big prime ( ~1K ) 
const ld EPS = 1e-9; 
const ld PI = 3.1415926535897932384626433832795; 
/*------------------------------------------------IO_OPERATORS---------------------------------------------*/ 
const int M = 57; 
char fl[M][M]; 
vector<pair<int, int>> dir = { { -1,0 },{ 0,-1 },{ 0,1 },{ 1,0 } }; 
bool tr(pair<int, int> st, pair<int, int> fn, vector<int> &mv) { 
    for (auto i : mv) { 
        st.x += dir[i].x;
        st.y += dir[i].y;
        if (st.x <0 || st.y < 0 || fl[st.x][st.y] == 0) { 
        	    return false; 
        	} 
        	if (st == fn) return true; 
    } 
    if (st != fn) return false; 
    return true; 
} 
inline void solve(ld tt) { int n, m; cin >> n >> m; pair<int, int> st, fn; for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) { char tmp; cin >> tmp; if (tmp == '.') { fl[i][j] = 1; } else if (tmp == 'S') { st = { i,j }; fl[i][j] = 1; } else if (tmp == 'E'){ fn = { i,j }; fl[i][j] = 1; } } } string s; cin >> s; vector<int> mv; for (auto i : s) { mv.pb(i - '0'); } int cnt = 0; do { if (tr(st, fn, mv)) { ++cnt; } } while (next_permutation(all(dir))); cout << cnt << endl; } 
int main() { 
ld tt = clock(); 
speedup; 
coutdouble; 
//int tst = 1; 
//cin >> tst; 
//scanf("%d", &tst); 
//while (tst-- > 0) { 
//while(true) 
solve(tt); 
//cout << "/*-----------------*/\n"; 
//} 
#ifdef LOCAL 
cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl; 
while (true); 
#endif // LOCAL 
return 0; 
}
	
	
	
	
	
	
//template<typename T, inline ostream &operator << (ostream &_out, const pair<T, U> &_p) { _out << _p.first << " " << _p.second; return _out; } template<typename T, typename U> inline istream &operator >> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; } template<typename T> inline ostream &operator << (ostream &_out, const vector<T> &_v) { if (_v.empty()) return _out; _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) _out << ' ' << *_it; return _out; } template<typename T> inline istream &operator >> (istream &_in, vector<T> &_v) { for (auto &_i : _v) _in >> _i; return _in; } template<typename T> inline ostream &operator << (ostream &_out, const set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; } template<typename T> inline ostream &operator << (ostream &_out, const multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; } template<typename T> inline ostream &operator << (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; } template<typename T> inline ostream &operator << (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) return _out; _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) _out << ' ' << *_it; return _out; } template<typename T, typename U> inline ostream &operator << (ostream &_out, const map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second << ')'; return _out; } template<typename T, typename U> inline ostream &operator << (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) return _out; _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) _out << ", (" << _it->first << ": " << _it->second