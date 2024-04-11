
#ifndef LOCAL
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif //LOCAL

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
const int ML_ = 200;
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


inline void solve() {
    int n, q;
    cin >> n >> q;
    deque<int> d;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    vector<pair<ll, int>> qq(q);
    for (int i = 0; i < q; ++i) {
        qq[i].y = i;
        cin >> qq[i].x;
    }
    vector<pair<int,int>> ans(q);
    sort(all(qq));
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        pair<int,int> ab = {d[0], d[1]};
        d.pop_front();
        d.pop_front();
        while (ptr < q && qq[ptr].x == i + 1) {
            ans[qq[ptr++].y] = ab;
        }
        if (ab.x < ab.y) swap(ab.x, ab.y);
        d.push_back(ab.y);
        d.push_front(ab.x);
    }


    for (int i = ptr; i < q; ++i) {
        ans[qq[i].y] = {d[0], d[(qq[i].x - n - 1) % (n - 1) + 1]};
    }

    for (auto &p : ans) {
        cout << p << endl;
    }
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