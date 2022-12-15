#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> adj(n + 1);
        vector<pair<int, int>> edges;
        vector<int> p(n + 1), d(n + 1), pidx(n + 1);
        vector<bool> vis(n + 1), blue(m + 1);
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
            edges.push_back({u, v});
        }

        function<void(int)> dfs = [&](int u){
            vis[u] = true;
            for(auto [to, idx]: adj[u]){
                if(to == p[u]) continue;
                if(vis[to]) continue;
                blue[idx] = true;
                p[to] = u;
                pidx[to] = idx;
                d[to] = d[u] + 1;
                dfs(to);
            }
        };

        p[1] = 1;
        d[1] = 0;
        dfs(1);

        vector<int> red;
        for(int i = 0; i < m; ++i)
            if(!blue[i])
                red.push_back(i);

        if(red.size() < 3){
            for(int i = 0; i < m; ++i)
                cout << blue[i];
            cout << "\n";
            continue;
        }

        bool cycle = true;
        auto [a1, a2] = edges[red[0]];
        auto [a3, a4] = edges[red[1]];
        auto [a5, a6] = edges[red[2]];

        int arr[6]{a1, a2, a3, a4, a5, a6};
        sort(arr, arr + 6);

        cycle = (arr[0] == arr[1]) && (arr[2] == arr[3]) && (arr[4] == arr[5]);

        if(cycle){
            if(d[a1] < d[a2])
                swap(a1, a2);

            blue[red[0]] = true;
            blue[pidx[a1]] = false;
        }

        for(int i = 0; i < m; ++i)
            cout << blue[i];
        cout << "\n";
        continue;
    }
}