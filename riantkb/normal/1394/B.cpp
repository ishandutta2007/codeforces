#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
const int M = 1000000007;

bool check(const vector<int>& v, int x, const vector<vector<bool>>& ok) {
    if (!ok[x][x]) return false;
    for (const auto& i : v) {
        if (!ok[i][x]) return false;
    }
    return true;
}

int dfs(int p, vector<int>& v, int k, const vector<vector<bool>>& ok) {
    if (p > k) return 1;
    int res = 0;
    for (int i = 0; i < p; ++i) {
        int x = p * k + i;
        if (check(v, x, ok)) {
            v.push_back(x);
            res += dfs(p + 1, v, k, ok);
            v.pop_back();
        }
    }
    return res;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<P>> edge(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        edge[u].push_back({ c, v });
    }
    int sz = k * k + k;
    vector<vector<int>> rcnt(n, vector<int>(sz));
    for (int i = 0; i < n; ++i) {
        sort(edge[i].begin(), edge[i].end());
        int s = edge[i].size();
        for (int j = 0; j < s; ++j) {
            ++rcnt[edge[i][j].second][s * k + j];
        }
    }
    vector<vector<bool>> ok(sz, vector<bool>(sz, true));
    for (const auto& cnt : rcnt) {
        for (int i = 0; i < sz; ++i) {
            if (cnt[i] == 0) continue;
            if (cnt[i] >= 2) {
                ok[i][i] = false;
            }
            for (int j = i + 1; j < sz; ++j) {
                if (cnt[i] > 0 && cnt[j] > 0) {
                    ok[i][j] = ok[j][i] = false;
                }
            }
        }
    }
    vector<int> v;
    cout << dfs(1, v, k, ok) << '\n';

    return 0;
}