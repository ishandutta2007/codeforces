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
using namespace __gnu_pbds;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
    
const int N = 200001;
int a[N];
vector<gp_hash_table<int, int>> g;
set<pair<int, int>> qs;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m, k, u, v;
    cin >> t;
    rep(z, t) {
        cin >> n >> m >> k;
        g.assign(n, gp_hash_table<int, int>());
        qs.clear();
        rep(i, m) {
            cin >> u >> v;
            u--; v--;
            g[u][v] = 1;
            g[v][u] = 1;
        }
        rep(i, n)
            qs.insert({g[i].size(), i});
        int fl = 0;
        while (!qs.empty() && (*qs.begin()).first < k) {
            int v = (*qs.begin()).second;
            qs.erase(qs.begin());
            if (g[v].size() == k - 1) {
                int pos = 0, f = 0;
                for (auto &pp : g[v]) {
                    rep(i, pos)
                        if (g[pp.first].find(a[i]) == g[pp.first].end()) {
                            f = 1;
                            break;
                        }
                    if (f)
                        break;
                    a[pos++] = pp.first;
                }
                if (!f) {
                    cout << "2\n";
                    rep(i, k - 1)
                        cout << a[i] + 1 << ' ';
                    cout << v + 1 << '\n';
                    fl = 1;
                    break;
                }   
            }
            for (auto &pp : g[v]) {
                qs.erase({g[pp.first].size(), pp.first});
                g[pp.first].erase(v);
                qs.insert({g[pp.first].size(), pp.first});
            }
            g[v].clear();
        }
        if (fl)
            continue;
        if (qs.empty())
            cout << "-1\n";
        else {
            cout << "1 " << qs.size() << '\n';
            for (auto &pp : qs)
                cout << pp.second + 1 << ' ';
            cout << '\n';
        }
    }
}