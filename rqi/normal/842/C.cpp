#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int values[200001];
int ans[200001];
set<int> c = {};

void dfs(int par, int s, set<int> b, int f) {
    if (s == 0) ans[s] = values[s];
    set<int> a;
    for(auto d: b) {
        a.insert(__gcd(d, values[s]));
        ans[s] = max(ans[s], __gcd(d, values[s]));
    }
    ans[s] = max(ans[s], f);
    a.insert(f);
    f = __gcd(values[s], f);
    for (auto u: adj[s]) if (u != par) dfs(s, u, a, f);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(-1,0,{},0);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}