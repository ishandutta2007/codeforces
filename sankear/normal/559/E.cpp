#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define pbk pop_back
#define prev _prev
#define rank _rank
#define next _next
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define left _left
#define right _right

typedef long long ll;
typedef long long int64;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const double inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 333;

int n;
pii a[N];
int p[N], left[N], right[N];
int b[N], val[N];
bool can[N][N];
int dp[N];
int max_val[N][N];

inline int get_max(int l, int r) {
    if (l > r) {
        return -1;
    }
    return max_val[l][r];
}

void dfs(int pv, int v) {
    can[pv][v] = true;
    for (int i = 0; i < n; ++i) {
        if (p[i] > v && left[i] <= v) {
            int max_pref = p[i];
            for (;;) {
                int new_pref = max(get_max(v + 1, p[i] - 1), get_max(p[i] + 1, max_pref));
                if (new_pref <= max_pref) {
                    break;
                }
                max_pref = new_pref;
            }
            if (!can[pv][max_pref]) {
                dfs(pv, max_pref);
            }
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    int m = 0;
    b[m++] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[i].fs, &a[i].sc);
        b[m++] = a[i].fs - a[i].sc;
        b[m++] = a[i].fs;
        b[m++] = a[i].fs + a[i].sc;
    }
    sort(a, a + n);
    sort(b, b + m);
    m = (int) (unique(b, b + m) - b);
    for (int i = 0; i < n; ++i) {
        p[i] = (int) (lower_bound(b, b + m, a[i].fs) - b);
        left[i] = (int) (lower_bound(b, b + m, a[i].fs - a[i].sc) - b);
        right[i] = (int) (lower_bound(b, b + m, a[i].fs + a[i].sc) - b);
    }
    for (int i = 0; i < m; ++i) {
        val[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[j] == i) {
                val[i] = right[j];
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int cur = -1;
        for (int j = i; j < m; ++j) {
            cur = max(cur, val[j]);
            max_val[i][j] = cur;
        }
    }
    for (int i = 0; i < m; ++i) {
        int pref = i;
        for (;;) {
            int new_pref = get_max(i, pref);
            if (new_pref <= pref) {
                break;
            }
            pref = new_pref;
        }
        dfs(i, pref);
    }
    for (int i = 0; i < m; ++i) {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        for (int j = m - 1; j >= i; --j) {
            if (can[i][j]) {
                dp[j + 1] = max(dp[j + 1], dp[i] + b[j] - b[i]);
                //break;
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}