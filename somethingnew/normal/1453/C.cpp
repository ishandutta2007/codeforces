#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "climits"
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int solve(const vector<vector<int>>& m, int tx) {
    int n = m.size();
    int ft = -1;
    int st = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (m[i][j] == tx) {
                if (ft == -1)
                    ft = i;
                st = i;
            }
        }
    }
    if (ft == -1)
        return 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int fts = -1, sts = -1;
        for (int j = 0; j < n; ++j) {
            if (m[i][j] == tx) {
                if (fts == -1)
                    fts = j;
                sts = j;
            }
        }
        if (fts == -1)
            continue;
        
        int ans1 = (sts - fts) * max(i, n - i - 1);
        int ans2 = max(sts, n - fts - 1) * max(st - i, i - ft);
        ans = max(ans1, max(ans2, ans));
    }
    return ans;
}
vector<vector<int>> rev(vector<vector<int>> matr) {
    vector<vector<int>> m1 = matr;
    int n = m1.size();
    for (int i = 0; i < n; ++i) {
        for (int h = 0; h < n; ++h) {
            m1[h][i] = matr[i][h];
        }
    }
    return m1;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> matr(n, vector<int>(n));
    for (auto &i : matr) {
        for (auto &j : i) {
            char c;
            cin >> c;
            j = c - '0';
        }
    }
    vector<int> ans(10);
    for (int i = 0; i < 10; ++i) {
        ans[i] = solve(matr, i);
    }
    matr = rev(matr);
    for (int i = 0; i < 10; ++i) {
        ans[i] = max(ans[i], solve(matr, i));
    }
    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
   int n;
   cin >> n;
   while (n--) solve();
}