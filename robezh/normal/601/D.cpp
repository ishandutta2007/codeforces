#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e5 + 50, B = 26, N = M;

int n;
string s;
int c[N];
vector<int> G[N];

struct Trie {
    int nxt[2 * M][B];
    int sz[2 * M];
    int cnt = 0;
    int mx = 0, mx_cnt = 0;

    void init() {
        memset(nxt, -1, sizeof(nxt));
    }

    void merge(int v, int u) {
        sz[v] = 1;
        for(int b = 0; b < B; b++) {
            if(nxt[v][b] != -1 && nxt[u][b] != -1) merge(nxt[v][b], nxt[u][b]);
            else if(nxt[u][b] != -1) {
                nxt[v][b] = nxt[u][b];
            }

            if(nxt[v][b] != -1) sz[v] += sz[nxt[v][b]];
        }
    }


    int dfs(int v, int p) {
        int root = cnt++;
        sz[root] = 1;
        for(int to : G[v]) {
            if(to == p) continue;
            int &nx = nxt[root][s[to]-'a'];
            if(nx == -1) nx = dfs(to, v);
            else merge(nx, dfs(to, v));
        }
        for(int b = 0; b < B; b++) if(nxt[root][b] != -1) sz[root] += sz[nxt[root][b]];
        
        if(sz[root] + c[v] > mx) mx = sz[root] + c[v], mx_cnt = 0;
        if(sz[root] + c[v] == mx) mx_cnt++;

        return root;
    }
} trie;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> c[i];
    cin >> s;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    trie.init();
    trie.dfs(0, -1);
    cout << trie.mx << "\n" << trie.mx_cnt << "\n";

}