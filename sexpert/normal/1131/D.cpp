#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2005;
vector<int> adj[MAXN], cadj[MAXN], ts;
char board[1005][1005];
int comp[MAXN], len[MAXN], pos[MAXN];
 
void flood(int s, int col) {
    comp[s] = col;
    for(auto v : adj[s])
        if(comp[v] == -1)
            flood(v, col);
}
 
void dfs(int s, int ti = 0) {
    len[s] = 1;
    for(auto v : cadj[s]) {
        if(len[v] == -1)
            dfs(v);
        len[s] = max(len[s], 1 + len[v]);
    }
    ts.push_back(s);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '=') {
                adj[i].push_back(n + j);
                adj[n + j].push_back(i);
            }
        }
    }
 
    memset(comp, -1, sizeof comp);
    int ccomp = 0;
    for(int i = 0; i < n + m; i++)
        if(comp[i] == -1) flood(i, ccomp++);
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '=')
                continue;
            int u = comp[i], v = comp[n + j];
            if(u == v) {
                cout << "No\n";
                return 0;
            }
            if(board[i][j] == '>')
                cadj[u].push_back(v);
            if(board[i][j] == '<')
                cadj[v].push_back(u);
        }
    }
 
    memset(len, -1, sizeof len);
    for(int i = 0; i < ccomp; i++)
        if(len[i] == -1) dfs(i);
 
    for(int i = 0; i < ccomp; i++)
        pos[ts[i]] = i;
 
    for(int i = 0; i < ccomp; i++) {
        for(auto j : cadj[i]) {
            if(pos[i] < pos[j]) {
                cout << "No\n";
                return 0;
            }
        }
    }
 
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
        cout << len[comp[i]] << " ";
    cout << endl;
    for(int i = 0; i < m; i++)
        cout << len[comp[n + i]] << " ";
    cout << endl;
}