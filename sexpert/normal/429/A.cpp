#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN], ans;
int h[MAXN], val[MAXN], goal[MAXN], flip[2];

void calc(int s, int p = 0) {
    h[s] = h[p] + 1;
    for(auto v : adj[s]) {
        if(v != p)
            calc(v, s);
    }
}

void dfs(int s, int p = 0) {
    val[s] = (val[s] + flip[h[s] % 2]) % 2;
    if(val[s] != goal[s]) {
        ans.push_back(s);
        flip[h[s] % 2]++;
    }
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
    if(val[s] != goal[s])
        flip[h[s] % 2]--;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 1; i <= n; i++)
        cin >> goal[i];
    h[0] = -1;
    calc(1);
    dfs(1);
    cout << ans.size() << endl;
    for(auto v : ans)
        cout << v << endl;
}