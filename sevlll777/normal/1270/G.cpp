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
        vector<int> A(1 + n);
        for (int i = 1; i <= n; i++) cin >> A[i];
        vector<bool> used(1 + n, false);
        vector<int> par(1 + n);
        int u = 1;
        while (!used[u]) {
            used[u] = true;
            par[u - A[u]] = u;
            u = u - A[u];
        }
        int uu = par[u];
        vector<int> ans;
        while (uu != u) {
            ans.pb(uu);
            uu = par[uu];
        }
        ans.pb(u);
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}