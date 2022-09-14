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

const int N = 200001;
int s[N], d[2][N], pm[N];
vector<int> g[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k, u, v;
    cin >> n >> m >> k;
    rep(i, k) {
        cin >> s[i];
        s[i]--;
    }
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i, 2) {
        int f = i * (n - 1);
        rep(j, n)
            d[i][j] = N;
        d[i][f] = 0;
        queue<int> q;
        q.push(f);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (int u : g[v])
                if (d[i][u] == N) {
                    d[i][u] = d[i][v] + 1;
                    q.push(u);
                }
        }
    }
    vector<pair<int, int>> a(k);
    rep(i, k)
        a[i] = {d[0][s[i]], d[1][s[i]]};
    sort(all(a));
    int l = 0, r = d[0][n - 1] + 1, md;
    for (int i = k - 1; i >= 0; i--)
        pm[i] = max(a[i].second, pm[i + 1]);
    while (r - l > 1) {
        md = (l + r) / 2;
        rep(i, k) {
            int pos = lower_bound(all(a), make_pair(md - a[i].second - 1, 0)) - a.begin();
            pos = max(pos, i + 1);
            if (pos < k && pm[pos] + a[i].first + 1 >= md) {
                l = md;
                break;
            }
        }
        if (l != md)
            r = md;
    }
    cout << l;
}