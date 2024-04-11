#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 7;

int n, m;
vector<int> adjacent[k_N], rev[k_N];

vector<int> p;
int state[k_N], cnt_left[k_N];

void dfs(int node, int ones = 0){
    state[node] = ones;
    //cout << node << " " << ones << " node ones" << endl;

    int next_state = (ones + 1) % 3;
    for(int to: adjacent[node]){
        //cout << "to " << node << " " << to << endl;
        state[to] = max(state[to], next_state);
        --cnt_left[to];
        if(cnt_left[to])
            continue;

        dfs(to, state[to]);
    }
}

void solve_test(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        adjacent[i].clear();
        rev[i].clear();
        state[i] = -1;
    }

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;

        adjacent[x].push_back(y);
        rev[y].push_back(x);
    }

    for(int i = 1; i <= n; ++i){
        cnt_left[i] = rev[i].size();
    }

    for(int i = 1; i <= n; ++i){
        if(rev[i].empty()){
            dfs(i);
        }
    }

    p.clear();
    for(int i = 1; i <= n; ++i)
        if(state[i] == 2)
            p.push_back(i);

    cout << p.size() << "\n";
    for(int x: p)
        cout << x << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve_test();
}