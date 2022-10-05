#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
int mod = ((int)1e9) + 7;
int pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return res;
}
int inv(int a) {
    return pow(a, mod - 2);
}
vector<vector<int>> g;
int r2 = 0;
vector<vector<int>> ver;
vector<pair<int, int>> dfs(int v, int p) {
    vector<pair<int, int>> now;
    for (auto i : g[v]) {
        if (i == p)
            continue;
        vector<pair<int, int>> neww = dfs(i, v);
        for (auto [u, d1] : now) {
            for (auto [u2, d2] : neww) {
                //cout << "AAA" << d1 << ' ' << d2 << endl;
                if (u > u2) {
                    r2 += ver[d2 + 1][d1 + 1];
                } else {
                    r2 += ver[d1 + 1][d2 + 1];
                }
                r2 %= mod;
            }
        }
        for (auto ii : neww) {
            if (ii.first < v)
                r2++;
            now.push_back(ii);
        }
    }
    for (auto &i : now) {
        i.second++;
    }
    now.push_back({v, 0});
    return now;
}
int findres(int v, vector<vector<int>> &ver) {
    dfs(v, -1);
    int res = r2 * inv(g.size());
    res %= mod;
    r2 = 0;
    //cout << res << endl;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ver.assign(n, vector<int>(n, 0));
    for (int i = 1; i < n; ++i) {
        ver[i][0] = 1;
    }
    int inv2 = inv(2);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            ver[i][j] = ver[i-1][j] * inv2 + ver[i][j - 1] * inv2;
            ver[i][j] %= mod;
        }
    }
    g.assign(n, {});
    for (int k = 0; k < n - 1;++k) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += findres(i, ver);
        res %= mod;
    }
    cout << res << '\n';
}