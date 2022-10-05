#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#define all(x) (x).begin(), (x).end()

using namespace std;
struct edge{
    int u;
    int num;
};
vector<int> ans;
vector<int> seen;
vector<vector<edge>> g;
void dfs(int v) {
    seen[v] = 1;
    for (auto [u, num] : g[v]) {
        if (seen[u] == 0) {
            ans.push_back(num);
            dfs(u);
        }
    }
}
vector<int> rankk;
vector<pair<int, int>> parent;
void make_set (int v) {
    parent[v] = make_pair(v, 0);
    rankk[v] = 0;
}

pair<int,int> find_set (int v) {
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set (parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

bool union_sets (int a, int b) {
    a = find_set (a) .first;
    b = find_set (b) .first;
    if (a != b) {
        if (rankk[a] < rankk[b])
            swap (a, b);
        parent[b] = make_pair (a, 1);
        if (rankk[a] == rankk[b])
            ++rankk[a];
        return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    rankk.assign(m + 1, 0);
    parent.assign(m + 1, {});
    for (int i = 0; i <= m; ++i) {
        make_set(i);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            int a, b;
            cin >> a;
            a--;
            b = m;
            if (union_sets(a, b)) {
                ans.push_back(i);
            }
        } else {
            int a, b;
            cin >> a >> b;
            a--;b--;
            if (union_sets(a, b)) {
                ans.push_back(i);
            }
        }
    }
    long long res = 1;
    long long mod = 1e9 + 7;
    for (int i = 0; i < ans.size(); ++i) {
        res *= 2;
        if (res >= mod)
            res -= mod;
    }
    sort(all(ans));
    cout << res << ' ' << ans.size() << '\n';
    for (auto i : ans)
        cout << i + 1 << ' ';
}