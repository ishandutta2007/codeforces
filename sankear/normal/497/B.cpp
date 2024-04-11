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
#include <stack>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define fs first
#define sc second

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

int a[N];
int s[2][N];
int wins[2];
vector<pii> ans;

inline int get_sum(int *s, int l, int r) {
    return s[r] - (l > 0 ? s[l - 1] : 0);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        if (i > 0) {
            for (int j = 0; j < 2; ++j) {
                s[j][i] += s[j][i - 1];
            }
        }
        ++s[a[i]][i];
    }
    for (int t = 1; t <= n; ++t) {
        wins[0] = wins[1] = 0;
        int last = -1;
        bool good = true;
        while (last < n - 1) {
            int pos = -1, l = last + 1, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (max(get_sum(s[0], last + 1, mid), get_sum(s[1], last + 1, mid)) >= t) {
                    pos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (pos == -1) {
                good = false;
                break;
            }
            int s0 = get_sum(s[0], last + 1, pos), s1 = get_sum(s[1], last + 1, pos);
            if (s0 > t && s1 > t) {
                good = false;
                break;
            }
            if (s0 == t && s1 == t) {
                good = false;
                break;
            }
            if (s0 == t) {
                assert(a[pos] == 0);
                ++wins[0];
            } else {
                assert(a[pos] == 1);
                ++wins[1];
            }
            last = pos;
        }
        if (!good) {
            continue;
        }
        if (wins[0] == wins[1]) {
            continue;
        }
        if (wins[0] > wins[1]) {
            if (a[n - 1] != 0) {
                continue;
            }
        } else {
            if (a[n - 1] != 1) {
                continue;
            }
        }
        ans.pb(mp(max(wins[0], wins[1]), t));
    }
    sort(all(ans));
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d %d\n", ans[i].fs, ans[i].sc);
    }
    return 0;
}