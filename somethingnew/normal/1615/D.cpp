#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
vector<vector<int>> g;
bool okidoki;
vector<vector<pair<int, int>>> g2;
map<pair<int, int>, int> ansiki;
vector<int> num;
int ch(int x) {
    int res = 0;
    for (int i = 0; i < 30; ++i) {
        if (x & (1 << i))
            res++;
    }
    return res % 2;
}
void dfs(int v, int c) {
    if (num[v] != -1) {
        if (num[v] != c)
            okidoki = 0;
        return;
    }
    num[v] = c;
    for (auto [i, cc] : g2[v]) {
        dfs(i, cc ^ c);
    }
}
void findans(int v, int p) {
    if (p != -1) {
        int x = ansiki[{v, p}];
        if (x != -1) {
            cout << v + 1 << ' ' << p + 1 << ' ' << x << '\n';
        } else {
            cout << v + 1 << ' ' << p + 1 << ' ' << (num[v] ^ num[p]) << '\n';
        }
    }
    for (auto i : g[v]) {
        if (i != p)
            findans(i, v);
    }
}
void solve() {
    int n, m;
    okidoki = 1;
    cin >> n >> m;
    num.assign(n, -1);
    g.assign(n, {});
    g2.assign(n, {});
    ansiki.clear();
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
        ansiki[{a, b}] = ansiki[{b, a}] = c;
        if (c != -1)
            c = ch(c);
        if (c != -1) {
            g2[a].push_back({b, c});
            g2[b].push_back({a, c});
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;a--;b--;
        g2[a].push_back({b, c});
        g2[b].push_back({a, c});
    }
    dfs(0, 0);
    for (int i = 0; i < n; ++i) {
        if (num[i] == -1) {
            dfs(i, 0);
        }
    }
    if (okidoki == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    findans(0, -1);
}
signed main() {
    int n;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    while (n--) {
        solve();
    }
}