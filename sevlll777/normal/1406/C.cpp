#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;
vector<bool> used;
vector<vector<int>> g;
vector<int> d, par;

void dfs(int v) {
    used[v] = true;
    d[v] = 1;
    for (auto u : g[v]) {
        if (!used[u]) {
            par[u] = v;
            dfs(u);
            d[v] += d[u];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        used.resize(n);
        g = {};
        g.resize(n);
        fill(used.begin(), used.end(), false);
        d.resize(n);
        par.resize(n);
        fill(d.begin(), d.end(), 0);
        fill(par.begin(), par.end(), 0);
        int kek, lol;
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            kek = x;
            lol = y;
            x--;
            y--;
            g[x].pb(y);
            g[y].pb(x);
        }
        dfs(0);
        if (n % 2 == 1) {
            cout << kek << ' ' << lol << '\n' << kek << ' ' << lol << '\n';
        } else {
            int gg = -1;
            for (int v = 0; v < n; v++) {
                if (d[v] == n / 2) {
                    gg = v;
                    break;
                }
            }
            if (gg == -1) {
                cout << kek << ' ' << lol << '\n' << kek << ' ' << lol << '\n';
            } else {
                int lul;
                for (auto ses : g[gg]) {
                    if (ses != par[gg]) {
                        lul = ses;
                    }
                }
                cout << lul + 1 << ' ' << gg + 1 << '\n';
                cout << lul + 1 << ' ' << par[gg] + 1 << '\n';
            }
        }
    }

}