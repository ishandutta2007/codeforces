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
#ifndef LOCAL
#define endl "\n"
#endif //LOCAL
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000 + 322;
const ll LLINF = 2LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL + 57;
const ll MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 200 * 1000 + 57;
const int P1M = 1336337; //Large prime ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;
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
const int ML_ = 128;
char mem_[ML_ * 1000000];
size_t ptr = 0;
void * operator new(size_t cnt) { if (ptr + cnt < sizeof mem_) { ptr += cnt; return  mem_ + ptr - cnt; } else { ptr = cnt; return mem_; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*----------------------------------------------------MATHS------------------------------------------------*/
inline ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(int a, int b) { return (ll)a*(ll)b / gcd(a, b); }
inline ll pwm(ll xx, ll pow, ll MD = MOD) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MD; mlt %= MD; } else { pow >>= 1; xx *= xx; xx %= MD; } }return mlt; }
inline ll pw(ll xx, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; } else { pow >>= 1; xx *= xx; } }return mlt; }
inline ll inv(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

int tree_a[4 * N], tree_b[4 * N];
int a, b, n;

void update(int pos, int add, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        tree_a[v] += add;
        if (tree_a[v] > a) {
            tree_a[v] = a;
        }
        tree_b[v] += add;
        if (tree_b[v] > b) {
            tree_b[v] = b;
        }
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, add, v * 2, tl, tm);
        else
            update(pos, add, v * 2 + 1, tm + 1, tr);
        tree_a[v] = tree_a[v * 2] + tree_a[v * 2 + 1];
        tree_b[v] = tree_b[v * 2] + tree_b[v * 2 + 1];
    }
}

int get_a(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree_a[v];
    int tm = (tl + tr) / 2;
    return get_a(l, min(r, tm), v * 2, tl, tm)
        + get_a(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
}

int get_b(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree_b[v];
    int tm = (tl + tr) / 2;
    return get_b(l, min(r, tm), v * 2, tl, tm)
        + get_b(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
}

inline void solve(ld tt) {
    int k, q;
    cin >> n >> k >> a >> b >> q;
    while (q-- > 0) {
        int cm, di, ai;
        cin >> cm;
        if (cm == 1) {
            cin >> di >> ai;
            --di;
            update(di, ai);
        }
        else {
            cin >> di;
            --di;
            cout << (get_b(0, di - 1) + get_a(di + k, n - 1)) << endl;
        }
    }
}

int main() {
    ld tt = clock();

    if (*infile != '\0')
        freopen(infile, "r", stdin);
    if (*outfile != '\0')
        freopen(outfile, "w", stdout);

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