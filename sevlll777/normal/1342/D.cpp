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
#define ld long double
#define pb push_back
#define str string
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> M(n), C(k+1);
    for (int i = 0; i < n; i++) cin >> M[i];
    for (int i = 1; i <= k; i++) cin >> C[i];
    vector<int> cnt(k + 1);
    for (auto x : M) cnt[x]++;
    for (int i = k - 1; i > 0; i--) {
        cnt[i] += cnt[i + 1];
    }
    int t = 0;
    for (int x = 1; x <= k; x++) {
        t = max(t, (cnt[x] + C[x] - 1) / C[x]);
    }
    cout << t << '\n';
    vector<vector<int>> ans(t);
    sort(M.begin(), M.end());
    for (int i = 0; i < n; i++) {
        ans[i%t].pb(M[i]);
    }
    for (auto p : ans) {
        cout << p.size() << ' ';
        for (auto y : p) cout << y << ' ';
        cout << '\n';
    }

}