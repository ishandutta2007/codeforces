#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <sstream>
#include <cassert>
#include <array>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = int(1e5) + 100;
const int LOG = 44;

int dp[LOG + 1][N];
int cnt[LOG], ex[LOG + 1];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll cur;
        scanf("%lld", &cur);
        bool fl = false;
        for (int j = 0; j < LOG; ++j) {
            if ((1LL << j) >= cur) {
                ++cnt[j];
                if ((1LL << j) == cur) {
                    ++ex[j + 1];
                }
                fl = true;
                break;
            }
        }
        assert(fl);
    }
    ex[0] = n;
    for (int i = 1; i <= LOG; ++i) {
        ex[i] = min(ex[i], ex[i - 1]);
    }
    for (int i = 0; i <= LOG; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[LOG][0] = 0;
    for (int i = LOG - 1; i >= 0; --i) {
        int max_val = -inf;
        for (int j = 0; j <= ex[max(i, 1)]; ++j) {
            if (j <= cnt[i]) {
                max_val = max(max_val, dp[i + 1][j]);
            }
            dp[i][j] = (max_val + j - cnt[i] >= 0 ? max_val + j - cnt[i] : -inf);
        }
    }
    vi ans;
    for (int i = 0; i <= ex[1]; ++i) {
        if (dp[0][i] >= 0) {
            ans.pb(i);
        }
    }
    if (sz(ans) == 0) {
        puts("-1");
        return 0;
    }
    for (int i = 0; i < sz(ans); ++i) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}