#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#undef NDEBUG
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define prev huprev
#define next hunext
#define link hulink
#define hash huhash
#define rank hurank
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

inline void solve() {
    string s;
    cin >> s;
    assert(s.substr(0, 4) == "IAO'");
    s = s.substr(4);
    ll ans = -42;
    for (int i = sz(s) - 1; i >= 0; --i) {
        if (i == sz(s) - 1) {
            if (s[i] == '9') {
                ans = 1989;
            } else {
                ans = 1990 + s[i] - '0';
            }
            continue;
        }
        ll x = 0, pw = 1;
        for (int j = i; j < sz(s); ++j) {
            x = x * 10 + s[j] - '0';
            pw *= 10;
        }
        ll y;
        if (ans - x < 0) {
            y = 0;
        } else {
            y = (ans - x) / pw;
            if (y * pw + x <= ans) {
                ++y;
            }
        }
        assert(y * pw + x > ans);
        ans = y * pw + x;
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}