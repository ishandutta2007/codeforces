#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using i64 = long long;
//using i128 = __int128;
#define MAXN 3005
#define MAXM 3005
#define M 1000000
#define K 17
#define MAXP 25
#define MAXK 55
#define MAXERR 105
#define MAXLEN 105
#define MDIR 10
#define MAXR 705
#define BASE 102240
#define MAXA 28
#define MAXT 100005
#define LIMIT 86400
#define MAXV 305
#define LEQ 1
#define EQ 0
#define OP 0
#define CLO 1
#define DIG 1
#define C1 0
#define C2 1
#define PLUS 0
#define MINUS 1
#define MUL 2
#define CLO 1
#define VERT 1
#define W 1
#define H 17
#define SPEC 1
#define MUL 2
#define CNT 3
#define ITER 1000
#define INF 1e9
#define EPS 1e-7
#define MOD 998244353
//#define MOD2 1000000007
#define FACT 100000000000000
#define SRC 0
#define PI acos(-1)
#define PUSH 0
#define POP 1
typedef long long ll;
typedef ll hash_t;
//typedef __int128_t lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ll> ilp;
typedef pair<ll,ii> pl;
typedef pair<ll, ll> pll;
typedef pair<ll,int> ppll;
typedef pair<ll,int> li;
typedef pair<ll,ll> iv;
typedef pair<double,int> ip;
typedef tuple<int,int,int> iii;
typedef tuple<ll, ll, ll> tll;
typedef tuple<ld, int, int> iit;
typedef tuple<int,int,ll> i3;
typedef vector<vector<int>> vv;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<vector<ll>> vll;
typedef complex<ld> cd;
typedef tuple<int,ll,ll> tpl;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define sz(A) (int)(A.size())
#define pb push_back
/*
void solve() {
    int k; cin >> k;
    vi v(7);
    int tot = 0;
    vi used;
    rep(i,0,7) {
        int a; cin >> a;
        v[i] = a;
        if (a == 1) tot++, used.pb(i);
    }
    int ans = INF;
    if (tot > k) {
        rep(i,0,sz(used)) {
            if (i + k > tot) break;
            ans = min(ans, used[i + k - 1] - used[i] + 1);
        }
    } else {
        assert(sz(used) == tot);
        int len = (k / tot) * 7;
        int rem = k % tot;
        cout << tot << ' ' << rem << '\n';
        if (rem) {
            rep(i,0,sz(used)) {
                if (i + rem > tot) {
                    ans = min(ans, len + used[(i + rem - 1) % tot] + 1 + 7 - used[i]);
                } else {
                    ans = min(ans, len + used[i + rem - 1] - used[i] + 1);
                }
            }
        } else ans = len;
    }
    cout << ans << '\n';
}
*/
void solve() {
    int k;cin>>k;
    vi arr(7);
    rep(i, 0, 7) {
        cin>>arr[i];
    }
    int tot = accumulate(arr.begin(), arr.end(), 0);
    int bst = INF;
    rep(st, 0, 7) {
        int cur = k;
        int days = 0;
        rep(i, st, 7) {
            days++;
            if (arr[i] == 1) {
                cur--;
                if (cur == 0) break;
            }
        }
        if (cur == 0) {
            bst = min(bst, days);continue;
        }
        int pr = cur/tot;
        int rem = cur%tot;
        if (rem == 0) {
            rem += tot;
            pr--;
        }
        rep(i, 0, 7) {
            days++;
            if (arr[i] == 1) {
                rem--;
                if (rem == 0)break;
            }
        }
        bst = min(bst, days + pr * 7);
    }
    cout<<bst<<"\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}