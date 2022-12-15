#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 17;

//vector<int> gr[N];
int gr[N], cnt[N];
vector<int> adj[N];
bool used[N];

int t;
int n;

void dfs(int v){
    gr[v] = t;
    if(v <= n){
        cnt[t]++;
    }
    used[v] = true;

    for(int u: adj[v]){
        if(used[u]){
            continue;
        }

        dfs(u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int k;

        cin >> k;

        for(int j = 0; j < k; j++){
            int v;

            cin >> v;

            //gr[i].push_back(v);
            adj[v].push_back(i + n + 1);
            adj[i + n + 1].push_back(v);
        }
    }

    for(int i = 1; i <= n + m; i++){
        t = i;
        if(!used[i]){
            dfs(i);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << cnt[gr[i]] << " ";
    }
    cout << "\n";

    return 0;
}