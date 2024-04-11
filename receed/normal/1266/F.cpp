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

const int N = 500001;
vector<int> g[N], li[N];
vector<pair<int, int>> cl[N];
int m1[N], m2[N], mu[N], ans[2 * N];

void dfs(int v, int p) {
    for (int u : g[v])
        if (u != p) {
            dfs(u, v);
            if (m1[u] + 1 > m1[v]) {
                m2[v] = m1[v];
                m1[v] = m1[u] + 1;
            }
            else if (m1[u] + 1 > m2[v])
                m2[v] = m1[u] + 1;
        }
}

void dfs2(int v, int p) {
    if (mu[v])
        li[v].push_back(mu[v]);
    li[v].push_back(0);
    for (int u : g[v])
        if (u != p) {
            li[v].push_back(m1[u] + 1);
            mu[u] = mu[v] + 1;
            if (m1[v] == m1[u] + 1)
                mu[u] = max(mu[u], m2[v] + 1);
            else
                mu[u] = max(mu[u], m1[v] + 1);
            dfs2(u, v);
        }
    sort(rall(li[v]));
    for (int i : li[v]) {
        if (cl[v].empty() || i != cl[v].back().first)
            cl[v].push_back({i, 1});
        else
            cl[v].back().second++;
    }
    for (int i = 1; i < li[v].size(); i++) {
        ans[li[v][i] * 2] = max(ans[li[v][i] * 2], i + 1);
        if (li[v][i] < li[v][i - 1])
            ans[li[v][i] * 2 + 1] = max(ans[li[v][i] * 2 + 1], i + 1);
        else
            ans[li[v][i] * 2 - 1] = max(ans[li[v][i] * 2 - 1], i + 1);
    }
    for (int u : g[v]) {
        if (u == p)
            continue;
        int cm = mu[v];
        if (m1[v] == m1[u] + 1)
            cm = max(cm, m2[v]);
        else
            cm = max(cm, m1[v]);
        cm = min(cm, m1[u]);
        int p1 = 0, p2 = 0, s1 = 0, s2 = 0;
        while (p1 < cl[v].size() || p2 < cl[u].size()) {
            if (p2 == cl[u].size() || p1 < cl[v].size() && cl[v][p1].first > cl[u][p2].first) {
                s1 += cl[v][p1].second;
                p1++;
            }
            else {
                s2 += cl[u][p2].second;
                p2++;
            }
            if (p1 && p2) {
                int ch = min(cm, min(cl[v][p1 - 1].first, cl[u][p2 - 1].first)) * 2;
                ans[ch] = max(ans[ch], s1 + s2 - 2);
            }
        }
    }
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
    ans[n + 1] = ans[n] = 1;
    dfs(0, -1);
    dfs2(0, -1);
    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 2]);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}