#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 4e5 + 10;
vector<int> adj[MAXN];
int tin[MAXN], val[MAXN], comp[MAXN], deg[MAXN], curt, nc;
vector<int> ccomp;

void dfs(int s) {
    tin[s] = ++curt;
    val[s] = tin[s];
    ccomp.push_back(s);
    for(auto v : adj[s]) {
        if(!tin[v]) {
            dfs(v);
            val[s] = min(val[s], val[v]);
        }
        else if(!comp[v])
            val[s] = min(val[s], tin[v]);
    }
    if(val[s] == tin[s]) {
        nc++;
        int z;
        do {
            z = ccomp.back(); ccomp.pop_back();
            comp[z] = nc;
            for(auto v : adj[z])
                if(comp[v] != nc)
                    deg[comp[v]]++;
        } while(z != s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n + 2, vector<char>(m + 2, '*'));
    vector<int> col(m + 2);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }

    auto idx = [&](int r, int c) { return m * (r - 1) + c; };
    auto coords = [&](int x) { 
        return "(" + to_string((x - 1)/m + 1) + ", " + to_string((x - 1) % m + 1) + ")";
    };

    for(int cr = n; cr >= 1; cr--) {
        for(int cc = 1; cc <= m; cc++) {
            if(v[cr][cc] != '#')
                continue;
            if(v[cr][cc - 1] == '#')
                adj[idx(cr, cc)].push_back(idx(cr, cc - 1));
            else if(col[cc - 1]) {
                //cout << "left " << cr << " " << cc - 1 << endl;
                adj[idx(cr, cc)].push_back(idx(col[cc - 1], cc - 1));
            }
            if(v[cr][cc + 1] == '#')
                adj[idx(cr, cc)].push_back(idx(cr, cc + 1));
            else if(col[cc + 1]) {
                //cout << "right " << cr << " " << cc + 1 << endl;
                adj[idx(cr, cc)].push_back(idx(col[cc + 1], cc + 1));
            }
            if(col[cc])
                adj[idx(cr, cc)].push_back(idx(col[cc], cc));
            if(v[cr - 1][cc] == '#')
                adj[idx(cr, cc)].push_back(idx(cr - 1, cc));
        }
        for(int cc = 1; cc <= m; cc++) {
            if(v[cr][cc] == '#')
                col[cc] = cr;
        }
    }

    /*for(int i = 1; i <= m * n; i++) {
        for(auto j : adj[i])
            cout << coords(i) << " -> " << coords(j) << '\n';
    }*/

    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v[i][j] != '#')
                continue;
            int u = idx(i, j);
            if(!comp[u])
                dfs(u);
        }
    }

    int ans = 0;
    for(int i = 1; i <= nc; i++)
        if(!deg[i])
            ans++;

    cout << ans << '\n';
}