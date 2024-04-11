#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
int tin[MAXN], low[MAXN], hr[MAXN], comp[MAXN], out[MAXN], comps, curt;
vector<int> cont[MAXN], adj[MAXN], st;

void dfs(int s) {
    tin[s] = low[s] = ++curt;
    st.push_back(s);
    for(auto v : adj[s]) {
        if(!tin[v]) {
            dfs(v);
            low[s] = min(low[s], low[v]);
        }
        else if(!comp[v])
            low[s] = min(low[s], tin[v]);
    }

    if(low[s] == tin[s]) {
        ++comps;
        int z;
        do {
            z = st.back(); st.pop_back();
            comp[z] = comps;
            cont[comps].push_back(z);
        } while(z != s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    for(int i = 1; i <= n; i++)
        cin >> hr[i];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if((hr[u] + 1) % h == hr[v])
            adj[u].push_back(v);
        if((hr[v] + 1) % h == hr[u])
            adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!comp[i]) dfs(i);
    for(int i = 1; i <= comps; i++) {
        for(auto u : cont[i]) {
            for(auto v : adj[u]) {
                if(comp[u] != comp[v])
                    out[comp[u]]++;
            }
        }
    }
    int msz = MAXN, bst = -1;
    for(int i = 1; i <= comps; i++) {
        if(out[i])
            continue;
        if(cont[i].size() < msz) {
            msz = cont[i].size();
            bst = i;
        }
    }
    cout << msz << '\n';
    for(auto x : cont[bst])
        cout << x << " ";
    cout << '\n';
}