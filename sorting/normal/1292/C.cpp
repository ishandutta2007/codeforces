#include <bits/stdc++.h>

using namespace std;

const int k_N = 3000 + 3;

int n;
vector<int> adjacent[k_N];
int parent[k_N];
int sz[k_N];

pair<long long, bool> dp[k_N][k_N][2];

long long get_dp(int up, int down, bool up_goes_down, int up_child){
    //cout << "get_dp " << up << " " << down << " " << up_goes_down << " " << up_child << endl;
    auto &[answer, solved] = dp[up][down][up_goes_down];
    if(solved)
        return answer;

    solved = true;
    answer = 1;

    answer *= sz[down];
    if(up_goes_down)
        answer *= sz[up];
    else
        answer *= (n - sz[up_child]);

    if(answer == 1)
        return answer;

    long long add = 0;
    for(int to: adjacent[down]){
        if(to == parent[down])
            continue;

        add = max(get_dp(up, to, up_goes_down, up_child), add);
    }

    if(!up_goes_down && parent[up] != -1)
        add = max(get_dp(parent[up], down, false, up), add);

    for(int to: adjacent[up]){
        if(to == parent[up])
            continue;
        if(to == up_child && !up_goes_down)
            continue;

        add = max(get_dp(to, down, true, -1), add);
    }

    answer += add;
    return answer;
}

void dfs(int node){
    sz[node] = 1;
    for(int to: adjacent[node]){
        if(to == parent[node])
            continue;

        parent[to] = node;
        dfs(to);

        sz[node] += sz[to];
    }
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

    parent[1] = -1;
    dfs(1);

    long long answer = 0;
    for(int node = 2; node <= n; ++node)
        answer = max(get_dp(parent[node], node, false, node), answer);

    cout << answer << "\n";
}