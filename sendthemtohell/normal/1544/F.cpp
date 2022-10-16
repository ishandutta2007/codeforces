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
/*
namespace db {
    ld tb[25][25], itb[25][25];
    ld msk_prod[21][1 << 21];
    ld stolb[25];

    void solve() {
        int n;
        cin >> n;
        //int inv10 = inv(10000, M);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> tb[i][j];
                tb[i][j] = tb[i][j] / 10000.;
                itb[i][j] = 1. / tb[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            stolb[i] = 1;
            for (int j = 0; j < n; ++j) {
                stolb[i] *= tb[j][i];
            }
            msk_prod[i][0] = 1;
        }
        for (int msk = 1; msk < (1 << n); ++msk) {
            int b = 0;
            for (; (msk & (1 << b)) == 0; ++b);
            int pm = (msk ^ (1 << b));
            for (int i = 0; i < n; ++i) {
                msk_prod[i][msk] = msk_prod[i][pm] * tb[i][b];
            }
        }

        ld ans = 0;

        for (int msk_al = 0; msk_al < (1 << (n + 2)); ++msk_al) {
            int msk = (msk_al >> 2);
            bool mdeg = (msk_al & 1);
            bool sdeg = (msk_al >> 1 & 1);

            ld to_add = 1;
            bool minus = (mdeg ^ sdeg);
            for (int b = 0; b < n; ++b) {
                if ((msk & (1 << b)) == 0) {
                    minus ^= 1;
                    to_add *= stolb[b];
                }
            }
            for (int i = 0; i < n; ++i) {
                if ((msk & (1 << i)) && !mdeg) {
                    to_add *= tb[i][i];
                    //p = p * itb[i][i];
                }
                if (!sdeg && (mdeg || i != n - 1 - i) && (msk & (1 << (n - 1 - i)))) {
                    to_add *= tb[i][n - 1 - i];
                }
            }

            for (int i = 0; i < n; ++i) {
                ld p = msk_prod[i][msk];
                if ((msk & (1 << i)) && !mdeg) {
                    p = p * itb[i][i];
                }
                if (!sdeg && (mdeg || i != n - 1 - i) && (msk & (1 << (n - 1 - i)))) {
                    p = p * itb[i][n - 1 - i];
                }
                to_add *= 1 - p;
            }
            if (minus) {
                ans = ans - to_add;
            }
            else {
                ans += to_add;
            }
        }

        cout << 1 - ans << endl;
    }
}*/

int tb[25][25];
int msk_prod[21][1 << 21];
int stolb[25];
const int M = 31607;

inline void solve() {
    //db::solve();
    //return;
    int n;
    cin >> n;
    int inv10 = inv(10000, M);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tb[i][j];
            tb[i][j] = tb[i][j] * inv10 % M;
        }
    }
    for (int i = 0; i < n; ++i) {
        stolb[i] = 1;
        for (int j = 0; j < n; ++j) {
            stolb[i] *= tb[j][i];
            stolb[i] %= M;
        }
        msk_prod[i][0] = 1;
    }
    for (int msk = 1; msk < (1 << n); ++msk) {
        int b = 0;
        for (; (msk & (1 << b)) == 0; ++b);
        int pm = (msk ^ (1 << b));
        for (int i = 0; i < n; ++i) {
            msk_prod[i][msk] = msk_prod[i][pm] * tb[i][b] % M;
        }
    }

    int ans = 0;

    for (int msk_al = 0; msk_al < (1 << (n + 2)); ++msk_al) {
        int msk = (msk_al >> 2);
        bool mdeg = (msk_al & 1);
        bool sdeg = (msk_al >> 1 & 1);

        int to_add = 1;
        bool minus = (mdeg ^ sdeg);
        for (int b = 0; b < n; ++b) {
            if ((msk & (1 << b)) == 0) {
                minus ^= 1;
                to_add *= stolb[b];
                to_add %= M;
            }
        }

        for (int i = 0; i < n; ++i) {
            if ((msk & (1 << i)) && !mdeg) {
                to_add *= tb[i][i];
                to_add %= M;
            }
            if (!sdeg && (mdeg || i != n - 1 - i) && (msk & (1 << (n - 1 - i)))) {
                to_add *= tb[i][n - 1 - i];
                to_add %= M;
            }
        }

        for (int i = 0; i < n; ++i) {
            int mm = msk;
            if (!mdeg) mm &= ~(1 << i);
            if (!sdeg) mm &= ~(1 << n - 1 - i);
            to_add *= M + 1 - msk_prod[i][mm];
            to_add %= M;
        }

        if (minus) {
            ans = ans + M - to_add;
            ans %= M;
        }
        else {
            ans += to_add;
            ans %= M;
        }
    }

    cout << (M + 1 - ans) % M << endl;
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