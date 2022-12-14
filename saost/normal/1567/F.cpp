#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int Gx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
const int Gy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int n, m, cnt, a[N][N], visit[N][N], color[N * N];
char s[N][N];
vector<int> S[N * N];

void DFS(int i, int j) {
    visit[i][j] = cnt;
    for(int w=0; w<8; ++w) {
        int x = i + Gx[w];
        int y = j + Gy[w];
        if (s[x][y] == '.' && !visit[x][y])
            DFS(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i<=n; ++i) cin >> s[i] + 1;

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) if (s[i][j] == 'X') {
        int dem = 0;
        for(int w=0; w<4; ++w) {
            int x = i + Gx[w];
            int y = j + Gy[w];
            if (s[x][y] == '.') ++dem;
        }
        if (dem & 1) return cout << "NO", 0;
        a[i][j] = dem * 5 / 2;
    }

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) if (s[i][j] == '.' && !visit[i][j]) {
        ++cnt;
        DFS(i, j);
    }

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) {
        if (visit[i][j-1] && visit[i][j+1] && visit[i][j-1] != visit[i][j+1]) {
            S[visit[i][j-1]].push_back(visit[i][j+1]);
            S[visit[i][j+1]].push_back(visit[i][j-1]);
        }
        if (visit[i-1][j] && visit[i+1][j] && visit[i-1][j] != visit[i+1][j]) {
            S[visit[i-1][j]].push_back(visit[i+1][j]);
            S[visit[i+1][j]].push_back(visit[i-1][j]);
        }
    }

    queue<int> Q;
    for(int i=1; i<=cnt; ++i) if (!color[i]) {
        Q.push(i);
        color[i] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for(int v : S[u]) {
                if (!color[v]) color[v] = color[u] ^ 3, Q.push(v);
                if (color[u] == color[v]) return cout << "NO", 0;
            }
        }
    }

    for(int i=1; i<=n; ++i) {
        int num = (i%2 ? 1 : 4);
        int col = color[visit[i][1]];
        a[i][1] = num;
        for(int j=2; j<=m; ++j) {
            if (s[i][j] == '.') {
                if (col != color[visit[i][j]]) num ^= 5;
                col = color[visit[i][j]];
                a[i][j] = num;
            }
        }
    }

    cout << "YES\n";
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j) cout << a[i][j] << " \n"[j==m];
}