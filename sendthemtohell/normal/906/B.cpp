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
const int N = 300 * 1000 + 57;
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
const int ML_ = 370;
char mem_[ML_ * 1000000];
size_t ptr = 0;
void * operator new(size_t cnt) { if (ptr + cnt < sizeof mem_) { ptr += cnt; return  mem_ + ptr - cnt; } else { ptr = cnt; return mem_; } }
void operator delete(void *) {}
#endif //ALLOC_LOCAL
/*----------------------------------------------------MATHS------------------------------------------------*/
inline int gcd(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
inline ll lcm(int a, int b) { return (ll)a*(ll)b / gcd(a, b); }
inline ll pwm(ll xx, ll pow, ll MD = MOD) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; xx %= MD; mlt %= MD; } else { pow >>= 1; xx *= xx; xx %= MD; } }return mlt; }
inline ll pw(ll xx, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= xx; xx *= xx; pow >>= 1; } else { pow >>= 1; xx *= xx; } }return mlt; }
inline ll inv(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/



inline void solve(ld tt) {
    int n, m;
    cin >> n >> m;
    if (n == m && n == 1) {cout << "YES\n1\n"; return;}
    vector<vector<int>> v;
    for (int i = 1; i <= n; ++i) {
        vector<int> row;
        for (int j = 1; j <= m; ++j) {
            row.pb((i - 1)*m + j);
        }
        v.pb(row);
    }
    if (n + m <= 5 && max(n,m) != 4) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    
    if (n == 3 && m == 3) {
        cout << "8 1 6\n3 5 7\n4 9 2\n";
        return;
    }
    vector<vector<int>> ans;
    if (n > m) {
        ans.resize(n);
        if (n == 4) {
            for (int j = 0; j < m; ++j) {
                vector<int> row = { v[1][j], v[3][j], v[0][j], v[2][j] };
                if (j & 1) {
                    reverse(all(row));
                }
                for (int i = 0; i < n; ++i) {
                    ans[i].pb(row[i]);
                }
                //ans.pb(row);
            }
        }
        else {
            for (int i = 0; i < m; ++i) {
                vector<int> row;
                for (int j = 0; j < n; j += 2) {
                    row.pb(v[j][i]);
                }
                for (int j = 1; j < n; j += 2) {
                    row.pb(v[j][i]);
                }
                rotate(row.begin(), row.begin() + i, row.end());
                for (int i = 0; i < n; ++i) {
                    ans[i].pb(row[i]);
                }
            }
        }
    }
    else {
        if (m == 4) {
            for (int i = 0; i < n; ++i) {
                vector<int> row = { v[i][1], v[i][3], v[i][0], v[i][2]};
                if (i & 1) {
                    reverse(all(row));
                }
                ans.pb(row);
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                vector<int> row;
                for (int j = 0; j < m; j += 2) {
                    row.pb(v[i][j]);
                }
                for (int j = 1; j < m; j += 2) {
                    row.pb(v[i][j]);
                }
                rotate(row.begin(), row.begin() + i, row.end());
                ans.pb(row);
            }
        }
    }
    for (auto &row : ans) {
        cout << row << endl;
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

    //int tst; cin >> tst;
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