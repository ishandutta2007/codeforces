#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#if ( _WIN32 || _WIN64 || __WIN32__ || __WIN64__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int T = 90000;

int a[T], res[T];
vi add[T];
vi del[T];
map<int, int> active;

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        a[i] = h * 60 * 60 + m * 60 + s;
        add[a[i]].pb(i);
    }
    int ans = 0;
    bool exists = false;
    pii right(-inf, -1);
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < sz(add[i]); ++j) {
            int col;
            if (sz(active) < m) {
                col = ++ans;
            } else {
                col = right.sc;
            }
            right = max(right, mp(i + t - 1, col));
            ++active[col];
            if (sz(active) == m) {
                exists = true;
            }
            res[add[i][j]] = col;
            del[i + t - 1].pb(col);
        }
        for (int j = 0; j < sz(del[i]); ++j) {
            if (active[del[i][j]] == 1) {
                active.erase(del[i][j]);
            } else {
                --active[del[i][j]];
            }
        }
    }
    if (!exists) {
        puts("No solution");
        return 0;
    }
    /*exists = false;
    for (int i = 0; i < T; ++i) {
        set<int> cur;
        for (int j = 0; j < n; ++j) {
            if (a[j] <= i && a[j] + t - 1 >= i) {
                cur.insert(res[j]);
            }
        }
        assert(sz(cur) <= m);
        if (sz(cur) == m) {
            exists = true;
        }
    }
    assert(exists);*/
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}