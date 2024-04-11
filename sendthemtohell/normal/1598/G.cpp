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

vector<int> M = { int(rd() % (MOD / 2)) + MOD / 2, int(rd() % (MOD / 2)) + MOD / 2 };

struct hsh {
    vector<int> hss;

    hsh() {
        hss.resize(sz(M));
    }

    void add_symbol(char c) {
        for (int i = 0; i < sz(hss); ++i) {
            hss[i] = (ll(hss[i]) * 10 + (c - '0')) % M[i];
        }
    }

    bool operator==(const hsh& oth) const {
        return hss == oth.hss;
    }
};


const int N = 500 * 1000 + 57;
hsh phs[N];
hsh phx[N];
vector<int> pw10[N];

hsh sum(const hsh& a, const hsh& b) {
    hsh x;
    for (int i = 0; i < sz(x.hss); ++i) {
        x.hss[i] = (a.hss[i] + b.hss[i]) % M[i];
    }
    return x;
}

hsh sub(const hsh& a, const hsh& b) {
    hsh x;
    for (int i = 0; i < sz(x.hss); ++i) {
        x.hss[i] = (a.hss[i] + M[i] - b.hss[i]) % M[i];
    }
    return x;
}

hsh mul(const hsh& a, int p) {
    hsh x;
    for (int i = 0; i < sz(x.hss); ++i) {
        x.hss[i] = a.hss[i] * ll(pw10[p][i]) % M[i];
    }
    return x;
}

hsh get_h(int l, int r) {
    hsh x;
    for (int i = 0; i < sz(x.hss); ++i) {
        x.hss[i] = (phs[r].hss[i] + M[i] - ll(phs[l].hss[i]) * pw10[r - l][i] % M[i]) % M[i];
    }
    return x;
}

bool pr(int i) {
    for (int d = 2; d * d <= i; ++d) {
        if (i % d == 0) return false;
    }
    return true;
}

inline void solve() {
    for (int i = 0; i < 2; ++i) {
        while (!pr(M[i])) ++M[i];
    }

    string s, x;
    cin >> s >> x;

    pw10[0].resize(sz(M), 1);
    for (int i = 1; i < N; ++i) {
        pw10[i] = pw10[i - 1];
        for (int j = 0; j < sz(M); ++j) {
            pw10[i][j] = ll(pw10[i][j]) * 10 % M[j];
        }
    }

    for (int i = 0; i < sz(s); ++i) {
        phs[i + 1] = phs[i];
        phs[i + 1].add_symbol(s[i]);
    }

    for (int i = 0; i < sz(x); ++i) {
        phx[i + 1] = phx[i];
        phx[i + 1].add_symbol(x[i]);
    }

    for (int len_m = max(sz(x) - 1, 1); len_m <= sz(x); ++len_m) {
        for (int pos = 0; pos + len_m <= sz(s); ++pos) {
            int l_oth;
            if (len_m == sz(x)) {
                int l = 0;
                int r = len_m + 1;

                while (r - l > 1) {
                    int m = (l + r) >> 1;
                    if (phx[m] == get_h(pos, pos + m)) {
                        l = m;
                    }
                    else {
                        r = m;
                    }
                }
                l_oth = sz(x) - l;
            }
            else {
                l_oth = sz(x) - 1;
            }

            for (int lo = max(l_oth - 1, 1); lo <= l_oth; ++lo) {
                if (pos + len_m + lo <= sz(s) && sum(get_h(pos, pos + len_m), get_h(pos + len_m, pos + len_m + lo)) == phx[sz(x)]) {
                    cout << pos + 1 << " " << pos + len_m << "\n" << pos + len_m + 1 << " " << pos + len_m + lo << endl;
                    return;
                }
                if (pos - lo >= 0 && sum(get_h(pos, pos + len_m), get_h(pos - lo, pos)) == phx[sz(x)]) {
                    cout << pos - lo + 1 << " " << pos << "\n" << pos + 1 << " " << pos + len_m << endl;
                    return;
                }
            }
        }
    }
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