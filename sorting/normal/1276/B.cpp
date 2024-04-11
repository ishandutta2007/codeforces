#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;

int n, m, a, b;
vector<int> adjacent[k_N];
bool used1[k_N], used2[k_N];

void dfs(int node, int f, bool used[]){
    used[node] = true;

    for(int to: adjacent[node]){
        if(used[to] || to == f)
            continue;

        dfs(to, f, used);
    }
}

void solve(){
    cin >> n >> m >> a >> b;

    for(int i = 1; i <= n; ++i)
        adjacent[i].clear();

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        used1[i] = false;
        used2[i] = false;
    }

    dfs(a, b, used1);
    dfs(b, a, used2);

    long long cnt_a = 0, cnt_b = 0;
    for(int i = 1; i <= n; ++i){
        if(i == a || i == b)
            continue;
        if(used1[i] && !used2[i])
            cnt_a++;
        else if(!used1[i] && used2[i])
            cnt_b++;
    }

    cout << cnt_a * cnt_b << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}