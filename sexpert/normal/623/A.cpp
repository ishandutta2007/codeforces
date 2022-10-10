#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 505;
int take[MAXN][MAXN], col[MAXN], cnt[MAXN], n, m;
bool good = true;

void dfs(int s, int x) {
    col[s] = x;
    for(int u = 1; u <= n; u++) {
        if(u == s)
            continue;
        if(take[s][u])
            continue;
        if(col[u] == -1) {
            dfs(u, x^2);
            continue;
        }
        if(col[u] == col[s])
            good = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v)
            swap(u, v);
        take[u][v] = take[v][u] = 1;
        cnt[u]++;
        cnt[v]++;
    }
    memset(col, -1, sizeof col);
    for(int i = 1; i <= n; i++) {
        if(col[i] == -1) {
            if(cnt[i] == n - 1) {
                col[i] = 1;
                continue;
            }
            dfs(i, 0);
        }
    }
    if(!good) {
        cout << "No\n";
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(take[i][j] && abs(col[i] - col[j]) == 2) {
                cout << "No\n";
                return 0;
            }
            if(!take[i][j] && abs(col[i] - col[j]) != 2) {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i++) {
        cout << (char)('a' + col[i]);
    }
    cout << '\n';
}