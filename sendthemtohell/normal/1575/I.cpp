#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
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

const int N = 100 * 1000 + 57;
int ss[N];
int l[N], r[N];
int nxt[N];
int h[N];
int par[N];
ll tr[4 * N];
vector<int> g[N];
int t = 0;

void dfs_sz(int v, int p, int ht = 0) {
    ss[v] = 1;
    h[v] = ht;
    par[v] = p;
    for (auto &u : g[v]) {
        if (u != p) {
            dfs_sz(u, v, ht + 1);
            ss[v] += ss[u];

            if (ss[u] > ss[g[v][0]]) {
                swap(u, g[v][0]);
            }
        }
    }
}

void dfs_hld(int v, int p) {
    //cout << v << " -> " << nxt[v] << endl;
    l[v] = t++;
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        nxt[u] = (u == g[v][0] ? nxt[v] : u);
        dfs_hld(u, v);
    }
    r[v] = t;
}

int n;


ll get_t(int v, int l, int r, int L, int R) {
    if (l >= R || r <= L) {
        return 0;
    }
    if (L <= l && r <= R) {
        return tr[v];
    }
    return get_t(v << 1, l, (l + r) >> 1, L, R) + get_t(v << 1 | 1, (l + r) >> 1, r, L, R);
}

void set_t(int v, int l, int r, int pos, int vl) {
    if (pos >= r || pos < l) {
        return;
    }
    if (r - l == 1) {
        tr[v] = vl;
        return;
    }
    set_t(v << 1, l, (l + r) >> 1, pos, vl);
    set_t(v << 1 | 1, (l + r) >> 1, r, pos, vl);
    tr[v] = tr[v << 1] + tr[v << 1 | 1];
}


ll get_on_path(int u, int v) {
    if (u == v) {
        return 0LL;
    }
    ll sum = -get_t(1, 0, n, l[v], l[v] + 1) - get_t(1, 0, n, l[u], l[u] + 1);
    while (nxt[u] != nxt[v]) {
        if (h[nxt[u]] < h[nxt[v]]) {
            swap(u, v);
        }

        //cout << nxt[u] << " -> " << u << endl;
        sum += 2 * get_t(1, 0, n, l[nxt[u]], l[u] + 1);
        u = par[nxt[u]];
    }
    if (h[u] < h[v]) swap(u, v);
    //cout << v << " -> " << u << endl;
    sum += 2 * get_t(1, 0, n, l[v], l[u] + 1);
    return sum;
}

inline void solve() {
    int q;
    n = 1000;
    q = 100000;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rd() % (MOD - 6);
    cin >> a;
    

    for (auto& aa : a) aa = abs(aa);

    for (int i = 0; i < n - 1; ++i) {
        int u = i + 2, v = i % (n / 2) + 1;
        cin >> u >> v;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs_sz(1, 0);
    dfs_hld(1, 0);

    for (int i = 0; i < n; ++i) {
        set_t(1, 0, n, l[i + 1], a[i]);
    }

    ll tot = 0;
    for (int i = 0; i < q; ++i) {
        int typ = (rd() & 1);
        cin >> typ;
        if (typ == 1) {
            int u = rd() % n + 1, c = rd() % (MOD - 6);
            cin >> u >> c;

            set_t(1, 0, n, l[u], abs(c));
        }
        else {
            int u = rd() % n + 1, v = rd() % n + 1;
            cin >> u >> v;

            //tot += get_on_path(u, v);
            cout << get_on_path(u, v) << endl;
        }
    }
    //cout << tot << endl;
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