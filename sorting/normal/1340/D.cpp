#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 7;

int n;
vector<int> adjacent[k_N];
vector<pair<int, int>> answer;

void dfs(int node, int begin_time, int parent = -1){
    answer.push_back({node, begin_time});

    int before, after;
    int children_count = adjacent[node].size() - (parent != -1);

    if(children_count <= begin_time - 1){
        before = children_count;
        after = 0;
    }
    else{
        before = begin_time - 1;
        after = children_count - (begin_time - 1);
    }

    int next_time;
    if(after)
        next_time = begin_time;
    else{
        next_time = begin_time -  1 - children_count;
        answer.push_back({node, next_time});
    }

    for(int to: adjacent[node]){
        if(to == parent)
            continue;

        ++next_time;
        dfs(to, next_time, node);

        answer.push_back({node, next_time});
        if(next_time >= begin_time + after){
            next_time = 0;
            answer.push_back({node, next_time});
        }
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

    dfs(1, 0);

    cout << answer.size() << "\n";
    for(auto p: answer)
        cout << p.first << " " << p.second << "\n";
}