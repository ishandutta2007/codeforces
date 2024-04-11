#ifndef LOCAL
#pragma GCC optimize("O3")
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
inline ll lcm(ll a, ll b) { return a*b / gcd(a, b); }
inline ll pwm(ll xx, ll pow, ll MD = MOD) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MD; mlt %= MD; } else { pow >>= 1; xx *= xx; xx %= MD; } }return mlt; }
inline ll pw(ll xx, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; } else { pow >>= 1; xx *= xx; } }return mlt; }
inline ll inv(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

struct vec {
    ld x, y;
    vec ort() {
        vec rt;
        rt.x = y;
        rt.y = -x;
        return rt;
    }
    vec &operator=(const vec &kk) {
        x = kk.x;
        y = kk.y;
        return *this;
    }
    vec operator*(ld coef) {
        vec rt;
        rt.x = x * coef;
        rt.y = y * coef;
        return rt;
    }
    vec operator+(vec op) {
        vec rt;
        rt.x = x + op.x;
        rt.y = y + op.y;
        return rt;
    }
    void norm() {
        ld coef = sqrt(x * x + y * y);
        coef = 1 / coef;
        *this = (*this) * coef;
    }
};

inline void solve(ld tt) {
    vec p, v;
    cin >> p.x >> p.y;
    cin >> v.x >> v.y;
    //if (v.x < 0) { v = v * (-1); }
    ld a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vec> out(7);
    v.norm();
    vec vort = v.ort();
    out[0] = p + v * b;
    out[1] = p + vort * (-(a / 2));
    out[2] = p + vort * (-(c / 2));
    out[3] = out[2] + v * (-d);
    out[4] = out[3] + vort * c;
    out[5] = out[4] + v * d;
    out[6] = p + vort * ((a / 2));
    for (auto &i : out) {
        cout << i.x << " " << i.y << endl;
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