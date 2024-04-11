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

string s;
const int N = 1000 * 10000;
int ps[2][N];

struct hsh {
    ull operator()(const pair<int, int>& p) const {
        return ull(p.x) << 32LL | p.y;
    }
};

unordered_map<pair<int, int>, int, hsh> mp;

void slv0(int n, int &at) {
    auto it = mp.find({ n, at });
    if (it != mp.end()) {
        at = it->y;
        return;
    }
    int sat = at;

    if (n == 1) {
        mp[{n, sat}] = at;
        return;
    }

    int lp = n / 2;
    int rp = n - lp;
    
    slv0(lp, at);
    if (at == -1) {
        mp[{n, sat}] = -1;
        return;
    }

    slv0(rp, at);
    if (at == -1) {
        mp[{n, sat}] = -1;
        return;
    }

    /*
    int pl = 1;
    int pr = 1;

    for (; at < sz(s) && pl <= lp && pr <= rp; ++at) {
        if (s[at] == '0') {
            ++pl;
        }
        else {
            ++pr;
        }
    }
    if (pl <= lp && pr <= rp) {
        mp[{n, sat}] = -1;
        at = -1;
        return;
    }
    */
    int l = at;
    int r = sz(s);
    if (ps[0][r] - ps[0][l] < lp && ps[1][r] - ps[1][l] < rp) {
        mp[{n, sat}] = -1;
        at = -1;
        return;
    }
    
    while (r - l > 1) {
        int m = (r + l) >> 1;
        if (ps[0][m] - ps[0][at] < lp && ps[1][m] - ps[1][at] < rp) {
            l = m;
        }
        else {
            r = m;
        }
    }
    at = r;

    mp[{n, sat}] = at;
    return ;
}

pair<vector<int>, vector<int>> slv(int n, int& at) {
    int sat = at;
    if (n == 1) {
        return { {1}, {-1, 0} };
    }
    int lp = n / 2;
    int rp = n - lp;
    auto ls = slv(lp, at);
    auto rs = slv(rp, at);

    if (sz(ls.x) != lp || sz(rs.x) != rp) {
        return { {}, {} };
    }

    int pl = 1;
    int pr = 1;
    pair<vector<int>, vector<int>> ret;
    ret.y.push_back(-1);
    for (; at < sz(s) && pl <= lp && pr <= rp; ++at) {
        if (s[at] == '0') {
            ret.y.push_back(ls.y[pl]);
            ls.x[ls.y[pl]] += pr - 1;
            ++pl;
        }
        else {
            ret.y.push_back(lp + rs.y[pr]);
            rs.x[rs.y[pr]] += pl - 1;
            ++pr;
        }
    }
    if (pl <= lp && pr <= rp) {
        return { {}, {} };
    }
    for (; pl <= lp; ++pl) {
        ret.y.push_back(ls.y[pl]);
        ls.x[ls.y[pl]] += pr - 1;
    }
    for (; pr <= rp; ++pr) {
        ret.y.push_back(lp + rs.y[pr]);
        rs.x[rs.y[pr]] += pl - 1;
    }
    ret.x.insert(ret.x.end(), all(ls.x));
    ret.x.insert(ret.x.end(), all(rs.x));
    return ret;
}



inline void solve() {
    mp.rehash(10000000);
    cin >> s;
    assert(sz(s) < N);
    for (int i = 1; i <= sz(s); ++i) {
        ps[0][i] = ps[0][i - 1] + (s[i - 1] == '0');
        ps[1][i] = ps[1][i - 1] + (s[i - 1] == '1');
    }
    int l = 1;
    int r = sz(s) + 1;
    while (r - l > 1) {
        int m = (r + l) >> 1;
        int ptr = 0;
        slv0(m, ptr);
        if (ptr == -1) {
            r = m;
        }
        else if (ptr <= sz(s)) {
            l = m;
        }
    }

    r += 20;
    int ptr = 0;
    do {
        --r;
        ptr = 0;
        slv0(r, ptr);
    } while (ptr != sz(s));
    
    ptr = 0;
    auto p = slv(r, ptr);
    assert(ptr == sz(s));
    cout << r << endl << p.x << endl;
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


    int tst = 1;
    //cin >> tst;
    while (tst-- > 0) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time: " << (ld)clock() / CLOCKS_PER_SEC << endl;
    //while (true);
#endif // LOCAL

    return 0;
}