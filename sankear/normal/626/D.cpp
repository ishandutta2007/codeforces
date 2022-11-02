#include <iostream>
#include <unistd.h>
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
#define len(s) sz(s)
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
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
typedef long double ldouble;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = 2020;
const int M = 5050;

int a[N];
ll cnt[M], cnt2[M];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    ll all = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && a[i] > a[j]) {
                assert(a[i] - a[j] < M);
                ++cnt[a[i] - a[j]];
                ++all;
            }
        }
    }
    ll all2 = all * all;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; i + j < M; ++j) {
            cnt2[i + j] += cnt[i] * cnt[j];
        }
    }
    for (int i = 1; i < M; ++i) {
        cnt2[i] += cnt2[i - 1];
    }
    ld ans = 0;
    if (all > 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && a[i] < a[j]) {
                    ans += 1.0 * cnt2[a[j] - a[i] - 1] / all2 / (n * (n - 1) - all);
                }
            }
        }
    }
    printf("%.18lf\n", (double) ans);
    return 0;
}