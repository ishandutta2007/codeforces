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
// #define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) ok = false;
        }
        if (!ok) {
            cout << -1;
        } else {
            vector<vector<int>> lol(26);
            for (int v = 0; v < 26; v++) lol[v].pb(v);
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    lol[a[i]-'a'].pb(b[i]-'a');
                }
            }
            vector<vector<int>> g(20);
            for (int v = 0; v < 26; v++) {
                sort(lol[v].begin(), lol[v].end());
                for (int i = 1; i < lol[v].size(); i++) {
                    if (lol[v][i - 1] != lol[v][i]) {
                        g[lol[v][i - 1]].pb(lol[v][i]);
                        g[lol[v][i]].pb(lol[v][i - 1]);
                    }
                }
            }
            vector<bool> used(20, false);
            int ans = 20;
            for (int v = 0; v < 20; v++) {
                if (!used[v]) {
                    ans--;
                    deque<int> q = {v};
                    while (!q.empty()) {
                        int u = q.front();
                        q.pop_front();
                        for (auto uu : g[u]) {
                            if (!used[uu]) {
                                q.pb(uu);
                                used[uu] = true;
                            }
                        }
                    }
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
}