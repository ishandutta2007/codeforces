#define _GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define int long long
#define dbl long double
#define pb push_back
#define str string
using namespace std;
const int M = 1e9 + 7;
int subtree[200009];
vector<vector<int>> gr;
vector<bool> used;

void get_sub(int v) {
    subtree[v] = 1;
    for (auto u : gr[v]) {
        if (!used[u]) {
            used[u] = true;
            get_sub(u);
            subtree[v] += subtree[u];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if (k == n) {
        cout << 0;
        return 0;
    }
    gr.resize(n);
    used.resize(n);
    fill(used.begin(), used.end(), false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].pb(b);
        gr[b].pb(a);
    }
    used[0] = true;
    get_sub(0);
    fill(used.begin(), used.end(), false);
    used[0] = true;
    deque<int> q = {0};
    vector<int> lvl(n);
    lvl[0] = 0;
    vector<int> tourist(n, 1);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto u : gr[v]) {
            if (!used[u]) {
                used[u] = true;
                q.pb(u);
                lvl[u] = 1 + lvl[v];
            }
        }
    }
    int ans = 0;
    vector<int> huy;
    for (int v = 0; v < n; v++) {
        huy.pb(lvl[v] - (subtree[v] - 1));
    }
    sort(huy.begin(), huy.end());
    for (int i = n - 1; i > n - 1 - k; i--) ans += huy[i];
    cout << ans;

}