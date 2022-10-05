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
#define all(x) (x).begin(), (x).end()

using namespace std;
vector<int> nums;
void dfs(int v, int p, vector<vector<int>> &g) {
    if (p != -1) {
        for (int i = 1; i < g[v].size(); ++i) {
            nums.push_back(v);
        }
    }
    for (auto i : g[v]) {
        if (i == p)
            continue;
        dfs(i, v, g);
    }
}
void solve(){
    nums.clear();
    int n;
    cin >> n;
    vector<int> w(n);
    for (auto &i : w)
        cin >> i;
    long long r1 = 0;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
        r1 += w[i];
        if (g[i].size() == 1)
            s = i;
    }
    dfs(s, -1, g);
    vector<int> add;
    for (int i = 0; i < n - 2; ++i) {
        add.push_back(w[nums[i]]);
    }
    sort(all(add));
    reverse(all(add));
    cout << r1 << ' ';
    for (int j = 0; j < n - 2; ++j) {
        r1 += add[j];
        cout << r1 << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}