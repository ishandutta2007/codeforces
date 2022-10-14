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
bitset<2008> used;
vector<vector<int>> g, gt;
vector<int> topsort;
int pogu = 0;

void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < (int) g[v].size(); i++) {
        if (!used[g[v][i]]) {
            dfs1(g[v][i]);
        }
    }
    topsort.pb(v);
}

void dfs2(int v) {
    used[v] = true;
    pogu++;
    for (int i = 0; i < (int) gt[v].size(); i++) {
        if (!used[gt[v][i]]) {
            dfs2(gt[v][i]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n);
    gt.resize(n);
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            if (A[i][j]) {
                g[i].pb(j);
                gt[j].pb(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs1(i);
    }
    int cnt = 0;
    used.reset();
    for (int i = 0; i < n; i++) {
        int v = topsort[n - 1 - i];
        if (!used[v]) {
            dfs2(v);
            if (pogu == n) {
                cout << "YES\n";
                exit(0);
            } else {
                cout << "NO\n";
                exit(0);
            }
        }
    }
}