#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;

int n;
vector<int> adjacent[k_N];

pair<int, int> dfs(int node, int p = -1){
    int odd = 1, even = 0;
    for(int to: adjacent[node]){
        if(to == p)
            continue;
        auto [even_add, odd_add] = dfs(to, node);
        odd += odd_add;
        even += even_add;
    }
    return {odd, even};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;

        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }

    auto [odd, even] = dfs(1);
    cout << min(odd, even) - 1 << "\n";
}