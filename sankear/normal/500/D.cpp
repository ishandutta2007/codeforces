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
#ifdef _WIN32 || _WIN64
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

ll res;
vector<pii> g[N];
ll sum[N];
int sz[N], a[N], b[N], c[N];
bool used[N];

void dfs(int v) {
    used[v] = true;
    sz[v] = 1;
    sum[v] = 0;
    for (int i = 0; i < sz(g[v]); ++i) {
        if (!used[g[v][i].fs]) {
            dfs(g[v][i].fs);
            ll cur = sum[g[v][i].fs] + 1LL * g[v][i].sc * sz[g[v][i].fs];
            res += sum[v] * sz[g[v][i].fs] + cur * sz[v];
            sz[v] += sz[g[v][i].fs];
            sum[v] += cur;
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        --a[i];
        --b[i];
        g[a[i]].pb(mp(b[i], c[i]));
        g[b[i]].pb(mp(a[i], c[i]));
    }
    res = 0;
    dfs(0);
    int m;
    cin >> m;
    ll d = 1LL * n * (n - 1) / 2;
    for (int i = 0; i < m; ++i) {
        int num, nc;
        scanf("%d %d", &num, &nc);
        --num;
        int u = a[num], v = b[num], diff = c[num] - nc;
        c[num] = nc;
        if (sz[u] > sz[v]) {
            swap(v, u);
        }
        res -= 1LL * diff * sz[u] * (n - sz[u]);
        double ans = 3.0 * res / d;
        printf("%.10lf\n", ans);
    }
    return 0;
}