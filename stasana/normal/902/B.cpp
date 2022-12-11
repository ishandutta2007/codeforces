#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& g, vector<bool>& used, vector<int>& need, int v, int back) {
    used[v] = true;
    int res = (back == need[v] ? 0 : 1);
    for (int i = 0; i < int(g[v].size()); ++i) {
        if (!used[g[v][i]]) {
            res += dfs(g, used, need, g[v][i], need[v]);
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> need(n);
    vector<bool> used(n);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int to;
        cin >> to;
        g[i].push_back(to - 1);
        g[to - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> need[i];
    }
    cout << dfs(g, used, need, 0, 0);
    return 0;
}