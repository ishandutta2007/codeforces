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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 100001;
vector<int> g[N], li;
int sz[N], n, ans[N];
ll res;

int fc(int v, int p) {
    sz[v] = 1;
    int c = v, cc;
    for (int u : g[v]) {
        if (u == p)
            continue;
        cc = fc(u, v);
        if (sz[u] * 2 >= n)
            c = cc;
        sz[v] += sz[u];
    }
    return c;
}

void dfs(int v, int p) {
    li.push_back(v);
    sz[v] = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        sz[v] += sz[u];
        res += sz[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c = fc(0, -1);
    dfs(c, -1);
    cout << res * 2 << '\n';
    rep(i, n)
        ans[li[i]] = li[(i + n / 2) % n];
    rep(i, n)
        cout << ans[i] + 1 << ' ';
}