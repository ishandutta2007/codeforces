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
const int N = int(1e5) + 100;

double dp[N];
int sz[N];
vi g[N];

void dfs1(int v) {
    sz[v] = 1;
    for (int u : g[v]) {
        dfs1(u);
        sz[v] += sz[u];
    }
}

void dfs2(int v) {
    for (int u : g[v]) {
        dp[u] = dp[v] + 1 + (sz[v] - sz[u] - 1) * 0.5;
        dfs2(u);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].pb(i);
    }
    dfs1(0);
    dp[0] = 1;
    dfs2(0);
    for (int i = 0; i < n; ++i) {
        printf("%.18lf ", dp[i]);
    }
    puts("");
    return 0;
}