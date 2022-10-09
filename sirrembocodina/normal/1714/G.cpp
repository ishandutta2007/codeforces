#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<vector<int>> sons;
vector<vector<int>> sons_a;
vector<vector<int>> sons_b;
vector<int> ans;
vector<int> sums_b;

void dfs(int v, int sum_a, int sum_b) {
    ans[v] = upper_bound(sums_b.begin(), sums_b.end(), sum_a) - sums_b.begin() - 1;
    for (int i = 0; i < sons[v].size(); i++) {
        int to = sons[v][i];
        int a = sons_a[v][i];
        int b = sons_b[v][i];
        sums_b.push_back(sum_b + b);
        dfs(to, sum_a + a, sum_b + b);
        sums_b.pop_back();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        sons.clear();
        sons_a.clear();
        sons_b.clear();
        ans.clear();
        sums_b.clear();
        int n;
        cin >> n;
        sons.resize(n);
        sons_a.resize(n);
        sons_b.resize(n);
        for (int i = 1; i < n; i++) {
            int p, a, b;
            cin >> p >> a >> b;
            p--;
            sons[p].push_back(i);
            sons_a[p].push_back(a);
            sons_b[p].push_back(b);
        }
        ans.resize(n);
        sums_b.push_back(0);
        dfs(0, 0, 0);
        for (int i = 1; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}