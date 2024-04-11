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

const int N = 100001;
vector<int> g[N];
int d1[N], d0[N], ans;

void dfs(int v, int p) {
    d1[v] = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        ans = max(ans, max(d1[v], d0[v]) + d0[u]);
        ans = max(ans, d0[v] + d1[u]);
        d1[v] = max(d1[v], d0[u] + 1);
        d0[v] = max(d0[v], max(d0[u], d1[u]) + (int) g[v].size() - 2);
    }
    ans = max(ans, d1[v]);
}


int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, u, v;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    cout << ans;
}