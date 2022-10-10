#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
bool bad[MAXN], inans[MAXN];
 
void test_case() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        { bad[i] = false; adj[i].clear(); inans[i] = false; }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int sz = 0;
    for(int i = 1; i <= n; i++) {
        if(bad[i])
            continue;
        inans[i] = true;
        sz++;
        for(auto v : adj[i])
            bad[v] = true;
    }
    if(sz <= n/2) {
        cout << sz << '\n';
        for(int i = 1; i <= n; i++)
            if(inans[i]) cout << i << " ";
        cout << '\n';
    }
    else {
        cout << n - sz << '\n';
        for(int i = 1; i <= n; i++)
            if(!inans[i]) cout << i << " ";
        cout << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while(t--)
        test_case();
}