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
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define str string
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(k);
    vector<int> os(n, false);
    for (int i = 0; i < k; i++) {
        cin >> A[i];
        A[i]--;
        os[A[i]] = true;
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    vector<int> depth1(n);
    vector<int> depthn(n);
    deque<pair<int, int>> q = {{0, 0}};
    vector<int> used(n, false);
    used[0] = true;
    depth1[0] = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop_front();
        for (auto u : graph[v.first]) {
            if (!used[u]) {
                used[u] = true;
                q.pb({u, v.second + 1});
                depth1[u] = v.second + 1;
            }
        }
    }
    q = {{n - 1, 0}};
    fill(used.begin(), used.end(), false);
    used[n - 1] = true;
    depthn[n - 1] = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop_front();
        for (auto u : graph[v.first]) {
            if (!used[u]) {
                used[u] = true;
                q.pb({u, v.second + 1});
                depthn[u] = v.second + 1;
            }
        }
    }
    int ans = depth1[n - 1];
    vector<int> D1(k), D2(k);
    for (int i = 0; i < k; i++) {
        D1[i] = depth1[A[i]];
        D2[i] = depthn[A[i]];
    }
    vector<pair<int, int>> D3;
    for (int i = 0; i < k; i++) {
        D3.pb({D1[i] - D2[i], i});
    }
    sort(D3.begin(), D3.end());
    vector<int> sufmax(k + 1);
    for (int i = k - 1; i >= 0; i--) {
        sufmax[i] = max(sufmax[i + 1], D2[D3[i].second]);
    }
    int balik = 0;
    for (int i = 0; i < k - 1; i++) {
        int kek = 1 + D1[D3[i].second] + sufmax[i + 1];
        balik = max(balik, kek);
    }
    ans = min(ans, balik);
    cout << ans;
}