#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 3;

int n, m, k, c[N], comp[N], cnt_comp = 0;
int color[N], comp_color[N];
bool invalid[N];
vector<int> adj[N];
array<int, 2> edges[N];

map<int, vector<pair<int, int>>> adj2[N];
vector<pair<int, bool>> adj3[N];

void dfs(int u){
    comp[u] = cnt_comp;

    for(int to: adj[u]){
        if(comp[to] || c[u] != c[to]) continue;
        color[to] = 3 - color[u];
        dfs(to);
    }
}

bool dfs2(int u){
    for(auto [to, diff]: adj3[u]){
        if(comp_color[to]){
            if((comp_color[u] != comp_color[to]) != diff)
                return false;
            continue;
        }
        if(diff) comp_color[to] = 3 - comp_color[u];
        else comp_color[to] = comp_color[u];
        
        if(!dfs2(to)) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];

    for(int i = 0; i < m; ++i){
        cin >> edges[i][0] >> edges[i][1];
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    for(int i = 1; i <= n; ++i){
        if(!comp[i]){
            cnt_comp++;
            color[i] = 1;
            dfs(i);
        }
    }

    for(int i = 0; i < m; ++i){
        if(comp[edges[i][0]] == comp[edges[i][1]]){
            if(color[edges[i][0]] == color[edges[i][1]]){
                invalid[c[edges[i][0]]] = true;
            }
        }
    }

    int cnt_valid = 0;
    for(int i = 1; i <= k; ++i)
        cnt_valid += !invalid[i];

    if(!cnt_valid){
        cout << "0\n";
        return 0;
    }

    for(int i = 0; i < m; ++i){
        auto [u, v] = edges[i];
        if(c[u] != c[v]){
            adj2[c[u]][c[v]].push_back({u, v});
            adj2[c[v]][c[u]].push_back({u, v});
        }
    }

    long long ans = (long long)(cnt_valid - 1) * (long long)cnt_valid / 2ll;
    for(int i = 1; i <= k; ++i){
        if(invalid[i]) continue;
        
        for(auto &it: adj2[i]){
            if(invalid[it.first]) continue;
            if(it.first > i) continue;

            //cout << "\n";
            //cout << i << " - " << it.first << "\n";

            vector<int> part;
            for(auto [u, v]: it.second){
                //cout << u << " " << v << " edge\n";
                part.push_back(comp[u]);
                part.push_back(comp[v]);
                adj3[comp[u]].push_back({comp[v], color[u] == color[v]});
                adj3[comp[v]].push_back({comp[u], color[u] == color[v]});
            }

            bool ok = true;
            for(int x: part){
                if(comp_color[x]) continue;
                comp_color[x] = 1;
                if(!dfs2(x)){
                    ok = false;
                    break;
                }
            }

            if(!ok) ans--;

            for(int x: part){
                adj3[x].clear();
                comp_color[x] = 0;
            }
        }
    }

    cout << ans << "\n";
}
/*
5 5 2
1 1 1 2 2
1 2
1 3
3 4
3 5
4 5
*/