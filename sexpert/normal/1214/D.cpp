#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e6 + 5;
vector<int> adj[MAXN];
int tin[MAXN], low[MAXN], cur;
bool art;

void dfs(int s) {
    tin[s] = low[s] = ++cur;
    for(auto v : adj[s]) {
        if(!low[v]) {
            dfs(v);
            if(s && low[v] >= tin[s])
                art = true;
            low[s] = min(low[s], low[v]);
        }
        else if(tin[v] < tin[s])
            low[s] = min(low[s], tin[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    vector<vector<int>> up(n, vector<int>(m)), down(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        cin >> board[i];
    up[0][0] = 1;
    down[n - 1][m - 1] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + j == 0 || board[i][j] == '#')
                continue;
            if(i > 0)
                up[i][j] |= up[i - 1][j];
            if(j > 0)
                up[i][j] |= up[i][j - 1];
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(i + j == m + n - 2 || board[i][j] == '#')
                continue;
            if(i < n - 1)
                down[i][j] |= down[i + 1][j];
            if(j < m - 1)
                down[i][j] |= down[i][j + 1];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!up[i][j] || !down[i][j])
                continue;
            if(i < n - 1 && down[i + 1][j] && up[i + 1][j]) {
                adj[m*i + j].push_back(m*(i + 1) + j);
                adj[m*(i + 1) + j].push_back(m*i + j);
                //out << m*i + j << " === " << m*(i + 1) + j << endl;
            }
            if(j < m - 1 && down[i][j + 1] && up[i][j + 1]) {
                adj[m*i + j].push_back(m*i + j + 1);
                adj[m*i + j + 1].push_back(m*i + j);
                //cout << m*i + j << " === " << m*i + j + 1 << endl;
            }
        }
    }
    if(!up[n - 1][m - 1]) {
        cout << "0\n";
        return 0;
    }
    if(n == 1 || m == 1) {
        cout << "1\n";
        return 0;
    }
    if(board[1][0] == '#' || board[0][1] == '#') {
        cout << "1\n";
        return 0;
    }
    art = false;
    dfs(0);

    if(art)
        cout << "1\n";
    else
        cout << "2\n";
}