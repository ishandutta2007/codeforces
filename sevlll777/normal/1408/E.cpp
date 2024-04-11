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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<int> A(m), B(n);
    for (int i = 0; i < m; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    vector<vector<pair<int, int>>> g(n + m);
    int M = 0;
    int ans = 0;
    for (int _ = 0; _ < m; _++) {
        int s;
        cin >> s;
        while (s--) {
            int x;
            cin >> x;
            x--;
            g[n + _].pb({x, A[_] + B[x]});
            g[x].pb({n + _, A[_] + B[x]});
            ans += A[_] + B[x];
            M++;
        }
    }
    vector<bool> used(n + m, false);
    vector<vector<int>> comps;
    for (int v = 0; v < n + m; v++) {
        if (!used[v]) {
            vector<int> comp;
            deque<int> q = {v};
            used[v] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop_front();
                comp.pb(u);
                for (auto uu : g[u]) {
                    if (!used[uu.first]) {
                        q.pb(uu.first);
                        used[uu.first] = true;
                    }
                }
            }
            comps.pb(comp);
        }
    }
    fill(used.begin(), used.end(), false);
    for (auto C : comps) {
        int v = C[0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qq;
        qq.push({0, v});
        while (!qq.empty()) {
            pair<int, int> c = qq.top();
            qq.pop();
            int v0 = c.second, weg = c.first;
            if (used[v0]) {
                continue;
            }
            used[v0] = true;
            ans += weg;
            for (auto p : g[v0]) {
                int u = p.first, wegg = p.second;
                if (!used[u]) {
                    qq.push({-wegg, u});
                }
            }
        }
    }

    cout << ans << '\n';
}