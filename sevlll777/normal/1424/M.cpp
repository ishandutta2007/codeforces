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
bitset<26> used;
vector<vector<int>> g(26);
vector<int> topsort;

void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < (int) g[v].size(); i++) {
        if (!used[g[v][i]]) {
            dfs1(g[v][i]);
        }
    }
    topsort.pb(v);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> W(n * k);
    vector<bool> bukva(26, false);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        for (int j = 0; j < k; j++) {
            cin >> W[p * n + j];
            for (auto c : W[p * n + j]) bukva[c-'a'] = true;
        }
    }
    vector<pair<int, int>> l;
    for (int i = 1; i < n * k; i++) {
        bool f = false;
        for (int j = 0; j < min(W[i - 1].size(), W[i].size()); j++) {
            if (W[i - 1][j] != W[i][j]) {
                g[W[i][j] - 'a'].pb(W[i - 1][j] - 'a');
                l.pb({W[i][j] - 'a', W[i - 1][j] - 'a'});
                f = true;
                break;
            }
        }
        if (!f) {
            if (W[i - 1].size() > W[i].size()) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (bukva[i] && !used[i]) dfs1(i);
    }
    vector<int> place(26);
    for (int i = 0; i < topsort.size(); i++) {
        place[topsort[i]] = i;
    }
    for (auto p : l) {
        if (place[p.first] < place[p.second]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    for (auto v : topsort) cout << (char) ('a' + v);
}