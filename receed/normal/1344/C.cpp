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
vector<int> g[N], ord;
int used[N], m1[N], m2[N], pos[N];

int dfs(int v) {
    used[v] = 1;
    for (int u : g[v])
        if (used[u] == 1 || used[u] == 0 && dfs(u))
            return 1;
    pos[v] = ord.size();
    ord.push_back(v);
    used[v] = 2;
    return 0;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, u, v;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    rep(i, n) {
        m1[i] = m2[i] = i;
        if (!used[i] && dfs(i)) {
            cout << -1;
            return 0;
        }
    }
    for (int i : ord)
        for (int j : g[i])
            m1[i] = min(m1[i], m1[j]);
    reverse(all(ord));
    for (int i : ord)
        for (int j : g[i])
            m2[j] = min(m2[j], m2[i]);
    int ans = 0;
    rep(i, n)
        if (m1[i] == i && m2[i] == i)
            ans++;
    cout << ans << '\n';
    rep(i, n) {
        if (m1[i] == i && m2[i] == i)
            cout << 'A';
        else
            cout << 'E';
    }
}