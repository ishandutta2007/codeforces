#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;
const int k_K = 9 + 3;

int n, k, m;
vector<pair<int, int>> adj[k_N];
vector<pair<int, int>> num[k_N];

bool p[k_K][k_K][k_K][k_K];
bool here[k_K][k_K];

int solve(int pos, vector<pair<int, int>> &v){
    if(pos == k + 1) return 1;
    int ans = 0;
    for(int i = 1; i <= pos; ++i){
        if(p[pos][i][pos][i]) continue;
        bool ok = true;
        for(auto [x, y]: v){
            if(p[x][y][pos][i]){
                ok = false;
                break;
            }
        }

        if(!ok) continue;
        v.push_back({pos, i});
        ans += solve(pos + 1, v);
        v.pop_back();
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    for(int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < adj[i].size(); ++j){
            auto [w, to] = adj[i][j];
            num[to].push_back({adj[i].size(), j + 1});
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j)
            for(int k1 = 1; k1 <= j; ++k1)
                here[j][k1] = false; 
    
        vector<pair<int, int>> v;
        for(auto [x, y]: num[i]){
            if(!here[x][y]){
                here[x][y] = true;
                for(auto [x2, y2]: v){
                    p[x][y][x2][y2] = true;
                    p[x2][y2][x][y] = true;
                }
                v.push_back({x, y});
            }
            else p[x][y][x][y] = true;
        }
    }

    vector<pair<int, int>> v;
    cout << solve(1, v) << "\n";
}