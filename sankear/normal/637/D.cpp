#pragma comment(linker, "/STACK:256000000")

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
const int N = int(2e5) + 100;

int n, m, s, d;
int a[N];
bool can[N];
set<int> points;
map<int, int> prev_point;

void dfs(int x) {
    int pos = upper_bound(a, a + n, x) - a;
    if (pos >= n || (a[pos] - 1) - x < s) {
        return;
    }
    for (;;) {
        auto it = points.lower_bound(a[pos] - 1);
        if (it == points.end() || *it - (a[pos] - 1) > d) {
            break;
        }
        int nx = *it;
        points.erase(it);
        prev_point[nx] = x;
        dfs(nx);
    }
}

void path(int x) {
    if (x == 0) {
        return;
    }
    int px = prev_point[x];
    path(px);
    int pos = upper_bound(a, a + n, px) - a;
    assert(pos < n);
    printf("RUN %d\n", (a[pos] - 1) - px);
    printf("JUMP %d\n", x - (a[pos] - 1));
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m >> s >> d;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (i + 1 < n && a[i] + 1 == a[i + 1]) {
            continue;
        }
        points.insert(a[i] + 1);
    }
    prev_point[0] = -1;
    dfs(0);
    if (prev_point.find(a[n - 1] + 1) == prev_point.end()) {
        puts("IMPOSSIBLE");
        return 0;
    }
    path(a[n - 1] + 1);
    if (a[n - 1] + 1 < m) {
        printf("RUN %d\n", m - (a[n - 1] + 1));
    }
    return 0;
}