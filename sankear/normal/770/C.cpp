#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <array>
#include <cstring>
#include <cassert>

using namespace std;

#define pb push_back
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define fs first
#define sc second

using ll = long long;
using vi = vector<int>;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);

const int N = 1e5 + 100;

bool need[N], is_main[N];
vi g[N], rg[N];
int deg[N], q[N];

void dfs(int v) {
    need[v] = true;
    for (int u : g[v]) {
        if (!need[u]) {
            dfs(u);
        }
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        is_main[num] = true;
    }
    for (int i = 0; i < n; ++i) {
        int sz;
        scanf("%d", &sz);
        g[i].resize(sz);
        for (int j = 0; j < sz; ++j) {
            scanf("%d", &g[i][j]);
            --g[i][j];
            rg[g[i][j]].pb(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        deg[i] = sz(g[i]);
        if (!need[i] && is_main[i]) {
            dfs(i);
        }
    }
    int l = 0, r = 0, need_cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (need[i]) {
            ++need_cnt;
        }
        if (need[i] && deg[i] == 0) {
            q[r++] = i;
        }
    }
    while (l < r) {
        int v = q[l++];
        for (int u : rg[v]) {
            if (need[u] && --deg[u] == 0) {
                q[r++] = u;
            }
        }
    }
    if (r == need_cnt) {
        cout << need_cnt << endl;
        for (int i = 0; i < need_cnt; ++i) {
            printf("%d ", q[i] + 1);
        }
        puts("");
        return 0;
    }
    puts("-1");
    return 0;
}