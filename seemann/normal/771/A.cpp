#include <bits/stdc++.h>
using namespace std;

vector<int> nxt[150001];
bool vis[150001];

int dfs(int v) {
    vis[v] = 1;
    int ret = 1;
    for(int w : nxt[v]) {
        if(!vis[w]) ret += dfs(w);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int _ = 0; _ < m ; _++) {
        int a, b;
        cin >> a >> b;
        nxt[a].push_back(b);
        nxt[b].push_back(a);
    }
    
    long long mm = 0;
    for(int v = 1; v <= n; v++) {
        if(!vis[v]) {
            long long x = dfs(v);
            mm += (x * (x-1)) / 2;
        }
    }
	
    cout << (m == mm ? "YES" : "NO");
    
    return 0;
}