#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3e5 + 3;

int n, m;
vector<int> adj[N];
short col[N];
bool vis[N];

void solve(){
    cin >> n >> m;
    fill(adj + 1, adj + n + 1, vector<int>());

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(vis + 1, vis + n + 1, false);
    fill(col + 1, col + n + 1, false);

    deque<int> q;
    q.push_front(1);
    col[1] = 1;
    vis[1] = false;

    while(!q.empty()){
        int u = q.front();
        q.pop_front();

        if(vis[u]) continue;
        vis[u] = true;

        if(col[u] == 1){
            for(int to: adj[u]){
                if(!vis[to]){
                    q.push_back(to);
                    col[to] = 2;
                }
            }
        }
        else{
            for(int to: adj[u]){
                if(!vis[to] && col[to] != 2){
                    q.push_front(to);
                    col[to] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        cnt += col[i] == 1;

    cout << cnt << "\n";
    for(int i = 1; i <= n; ++i)
        if(col[i] == 1)
            cout << i << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}