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
#define int long long
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> batya, batyaind;
vector<vector<int>> deti;
vector<int> seen;
void dfs(int v, int p = -1, int pind = -1) {
    if (seen[v])
        return;
    seen[v] = 1;
    batyaind[v] = pind;
    batya[v] = p;
    for (auto i : g[v]) {
        dfs(i.first, v, i.second);
    }
}
vector<int> ans;
vector<int> c, post;
int x;
int stroika(int v) {
    if (v == 0) {
        return 0;
    }
    if (post[v] != -1){
        c[post[v]] += c[v];
        c[v] = 0;
        return post[v] = stroika(post[v]);
    }
    if (c[v] >= x) {
        ans.push_back(batyaind[v]);
        c[batya[v]] += c[v] - x;
        c[v] = 0;
        return post[v] = stroika(batya[v]);
    }
    return v;
}
void edfs(int v){
    for (auto i : deti[v]) {
        if (post[i] == -1) {
            ans.push_back(batyaind[i]);
        }
        edfs(i);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m >> x;
    c.assign(n, 0);
    int s = 0;
    for (auto &i : c){
        cin >> i;
        s += i;
    }
    if (s < n * x - x) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    g.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    seen.assign(n, 0);
    batya.assign(n, 0);
    batyaind.assign(n, 0);
    deti.assign(n, {});
    post.assign(n, -1);
    dfs(0);
    for (int i = 0; i < n; ++i) {
        stroika(i);
        seen[i] = 0;
        if (i != 0)
            deti[batya[i]].push_back(i);
    }
    edfs(0);
    for (auto i : ans)
        cout << i + 1 << '\n';
}