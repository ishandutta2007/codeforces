#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 26;
int G[MX][MX];
string s;

bool dfs(int u, int pu, vector<bool> &vis, vector<int> &res) {
    if (vis[u]) return false;
    vis[u] = true;
    res.push_back(u);
    bool r = true;
    for (int v = 0; v < 26; v++) {
        if (G[u][v] == 0) continue;
        if (v == pu) continue;
        r &= dfs(v, u, vis, res);
    }
    return r;
}

void solve() {
    memset(G, 0, sizeof G);
    for (int i = 0; i + 1 < s.length(); i++) {
        int a = s[i] - 'a';
        int b = s[i + 1] - 'a';
        G[a][b] = G[b][a] = 1;
    }

    vector<bool> vis(26, false);
    vector<int> res;
    for (int i = 0; i < 26; i++) {
        int deg = 0;
        for (int j = 0; j < 26; j++) deg += G[i][j];
        if (deg == 0) {
            vis[i] = true;
            res.push_back(i);
        } else if (deg == 1 && !vis[i]) {
            if (!dfs(i, -1, vis, res)) {
                cout<<"NO\n";
                return;
            }
        } else if (deg > 2) {
            cout<<"NO\n";
            return;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    for (int i = 0; i < res.size(); i++)
        cout <<(char)('a'+res[i]);
    cout<<"\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        solve();
    }
    
    return 0;
}