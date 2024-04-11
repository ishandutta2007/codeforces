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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(n), ans(n, -1);
        vector<vector<int>> b(n + 1);
        rep(i, n) {
            cin >> a[i];
            b[a[i]].push_back(i);
        }
        rep(i, n + 1) {
            if (b[i].empty())
                continue;
            int mx = max(b[i][0], n - 1 - b[i].back());
            rep(j, (int) b[i].size() - 1)
                mx = max(mx, b[i][j + 1] - b[i][j] - 1);
            if (ans[mx] == -1)
                ans[mx] = i;
        }
        rep(i, n - 1)
            if (ans[i] != -1 && (ans[i + 1] == -1 || ans[i + 1] > ans[i]))
                ans[i + 1] = ans[i];
        rep(i, n)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}