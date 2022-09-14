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
vector<int> g[N * 2];
int used[N * 2], cs = 1, fin[N * 2];

void dfs(int v) {
    if (!fin[v])
        cs = 0;
    used[v] = 1;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m, x, y;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        int ans = 0;
        rep(i, m) {
            cin >> x >> y;
            x--; y--;
            if (x == y)
                continue;
            ans++;
            g[x].push_back(n + y);
            g[n + y].push_back(x);
            fin[x] = fin[n + y] = 1;

            g[x].push_back(n + x);
            g[n + x].push_back(x);
            g[y].push_back(n + y);
            g[n + y].push_back(y);
        }
        rep(i, 2 * n)
            if (!used[i] && !g[i].empty()) {
                cs = 1;
                dfs(i);
                ans += cs;
            }
        cout << ans << '\n';
        rep(i, 2 * n) {
            used[i] = 0;
            g[i].clear();
            fin[i] = 0;
        }
    }
}