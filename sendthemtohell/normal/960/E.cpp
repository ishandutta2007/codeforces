#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif

#define _SCL_SECURE_NO_WARNINGS
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
const ld PI = acos(-1.);//3.1415926535897932384626433832795
const ld EPS = 1e-7;
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
const int ML_ = 800;
char mem_[ML_ * 1024 * 1024];
size_t _ptr = 0, _magic = 21323400;
void * operator new(size_t cnt) { if (_ptr + cnt < sizeof mem_) { _ptr += cnt; return  mem_ + _ptr - cnt; } else { assert(false);  _ptr = cnt + _magic; return mem_ + _magic; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*-----------------------------------------------------MATH------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline int pwm(ll xx, ll pow, int MD = MOD) { if (pow < 0) { return pwm(pwm(xx, MD - 2, MD), -pow, MD); } ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; mlt %= MD; } xx *= xx; pow >>= 1; xx %= MD; } return (int)mlt; }
//inline ll gcdexm(ll a, ll b, ll &x, ll &y, ll p) { if (b == 0) { x = 1; y = 0; return a; }ll xx, yy; ll gc = gcdexm(b, a % b, yy, xx, p); x = xx; y = ((yy - (a / b) * xx) % p + p) % p; return gc; } //returns x = inv(a) mod p, p being not prime. returns gcd(x, p)
//inline ll gcdex(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; }ll xx, yy; ll gc = gcdex(b, a % b, yy, xx); x = xx; y = yy - (a / b) * xx; return gc; }
inline int inv(ll r, int _mod = MOD) { return pwm(r % _mod, _mod - 2, _mod); }
/*-----------------------------------------------------CODE------------------------------------------------*/

const int N = 2 * 100 * 1000 + 57;
vector<int> g[N];
int val[N];
ll dp[N][4]; // from && ev -> 0, from && odd -> 1, to && even -> 2, to && odd -> 1
ll cnt[N][2];
ll ans = 0;

void dfs(int v, int p = -1) {
    //ll dp0 = 0, dp1 = 0, dp2 = 0, dp3 = 0;
    cnt[v][0] = 1;
    dp[v][0] = val[v];
    dp[v][2] = val[v];
    for (auto u : g[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v][0] = (dp[v][0] - dp[u][1] + cnt[u][1] * val[v]) % MOD;
        dp[v][1] = (dp[v][1] - dp[u][0] + cnt[u][0] * val[v]) % MOD;
        dp[v][2] = (dp[v][2] + dp[u][3] + cnt[u][1] * val[v]) % MOD;
        dp[v][3] = (dp[v][3] + dp[u][2] - cnt[u][0] * val[v]) % MOD;
        cnt[v][0] += cnt[u][1];
        cnt[v][1] += cnt[u][0];
    }
    for (auto u : g[v]) {
        if (u == p) continue;
        ll dp0x = (dp[v][0] + dp[u][1] - cnt[u][1] * val[v]) % MOD;
        ll dp1x = (dp[v][1] + dp[u][0] - cnt[u][0] * val[v]) % MOD;
        ll cnt1x = cnt[v][1] - cnt[u][0];
        ll cnt0x = cnt[v][0] - cnt[u][1];
        //ans += (dp0x + dp1x) * (dp[u][2] + dp[u][3]) % MOD;
        //cerr << v << " -> " << u << " : " <<  dp0x << " " << dp1x << endl;
        ans += dp0x * (cnt[u][1] - cnt[u][0])% MOD;
        ans += dp1x * (cnt[u][1] - cnt[u][0]) % MOD;
        ans += dp[u][2] * (cnt1x + cnt0x) % MOD;
        ans += dp[u][3] * (cnt1x + cnt0x) % MOD;
    }
    ans += (dp[v][0] + dp[v][1]) % MOD;
}

inline void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i + 1];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    //for (int i = 1; i <= n; ++i) {
    //    cout << i << " -> " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    //}
    cout << (ans % MOD + MOD) % MOD << endl;
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


    return 0;
}