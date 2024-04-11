#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200001;
int h[N], sz[N], a[N];
vector<int> g[N];
int n, k;

void dfs(int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        h[u] = h[v] + 1;
        dfs(u, v);
        sz[v] += sz[u];
    }
    a[v] = h[v] - sz[v] + 1;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v;
    cin >> n >> k;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    sort(a, a + n);
    ll ans = 0;
    for (int i = n - k; i < n; i++)
        ans += a[i];
    cout << ans;
}