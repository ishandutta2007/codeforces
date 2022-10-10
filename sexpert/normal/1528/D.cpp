#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 606;
const int INF = 2e9 + 9;
int to[MAXN][MAXN], vi[MAXN], di[MAXN][MAXN], n, m;

void solve(int s) {
    for(int i = 0; i < n; i++) {
        to[n][i] = to[s][i];
        di[s][i] = INF;
    }
    memset(vi, 0, sizeof vi);

    di[s][n] = 0;
    int used = 0;
    while(used <= n + 1) {
        int mdis = INF, u = -1;
        for(int i = 0; i <= n; i++) {
            if(vi[i])
                continue;
            if(mdis > di[s][i]) {
                mdis = di[s][i];
                u = i;
            }
        }
        used++;
        vi[u] = 1;
        for(int v = 0; v < n; v++) {
            if(!to[u][v])
                continue;
            int nxt = (v + mdis) % n;
            if(di[s][nxt] > mdis + to[u][v])
                di[s][nxt] = mdis + to[u][v];
        }
        if(u != n)
            if(di[s][(u + 1) % n] > mdis + 1)
                di[s][(u + 1) % n] = mdis + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        to[a][b] = c;
    }

    for(int i = 0; i < n; i++) {
        solve(i);
        di[i][i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << di[i][j] << " ";
        }
        cout << '\n';
    }
}