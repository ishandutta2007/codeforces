#include <bits/stdc++.h>

using namespace std;

const int k_N = 1e5 + 3;

int n, m;
vector<pair<int, int>> adj[k_N];
short used[k_N];

vector<long long> v;

bool col[k_N];
long long val[k_N];

void dfs3(int u){
    used[u] = 2;

    for(auto [to, sum]: adj[u]){
        if(used[to] == 2) continue;
        val[to] = sum - val[u];
        dfs3(to);
    }
}

void dfs2(int u){
    used[u] = 2;

    for(auto [to, sum]: adj[u]){
        if(used[to] == 2){
            if(val[u] + val[to] != sum){
                cout << "NO\n";
                exit(0);
            }
            continue;
        }

        val[to] = sum - val[u];
        dfs2(to);
    }
}

bool dfs(int u){
    used[u] = 1;
    if(col[u]) v.push_back(-val[u]);
    else v.push_back(val[u]);

    for(auto [to, sum]: adj[u]){
        if(used[to]){
            //cout << "u to " << u << " " << to << "\n";
            //cout << col[u] << " " << col[to] << "\n";
            if(col[to] == col[u]){
                long long x = (sum - val[u] - val[to]) / 2;
                if(!col[u]) x = -x;
                //cout << val[u] << " " << x << " val[u] x\n";
                if(col[u]) val[u] += x;
                else val[u] -= x;
                //cout << val[u] << " val[u]\n";
                dfs2(u);
                return true; 
            }
            else if(val[to] + val[u] != sum){
                cout << "NO\n";
                exit(0);
            }
            continue;
        }

        col[to] = !col[u];
        val[to] = sum - val[u];
        if(dfs(to)) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, 2 * c});
        adj[b].push_back({a, 2 * c});
    }

    for(int i = 1; i <= n; ++i){
        if(!used[i]){
            v.clear();
            col[i] = true;
            val[i] = 0;
            //cout << "i: " << i << "\n";
            if(!dfs(i)){
                sort(v.begin(), v.end());
                //for(long long x: v)
                //    cout << x << " ";
                //cout << "\n";
                val[i] = v[v.size() / 2];
                dfs3(i);
            }
        }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; ++i){
        if(val[i] == -1) cout << "-";

        if(val[i] & 1) cout << (val[i] / 2) << ".5";
        else cout << (val[i] / 2) << ".0";

        if(i == n) cout << "\n";
        else cout << " ";
    }
}