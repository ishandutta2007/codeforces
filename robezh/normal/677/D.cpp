#include <bits/stdc++.h>
using namespace std;

const int N = 305, INF = (int)1e9;
typedef pair<int, int> P;
typedef pair<P, int> Pi;

int n, m, p;
int num[N][N];
vector<P> cor[N*N];
int fres[N][N];
int mx[N][N];
int vis[N];
vector<Pi> upds;
vector<int> row;

int main() {
    cin >> n >> m >> p;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> num[i][j];
        cor[num[i][j]].push_back({i, j});
    }
    memset(mx, 0x3f, sizeof(mx));
    for(auto p : cor[1]) {
        mx[p.first][p.second] = p.first + p.second;
        if(!vis[p.first]) row.push_back(p.first), vis[p.first] = true;
    }
    for(int i = 2; i <= p; i++) {
        for(int r : row) {
            int cur = INF;
            for(int j = 0; j < m; j++) {
                cur++;
                cur = min(cur, mx[r][j]);
                mx[r][j] = cur;
            }
            cur = INF;
            for(int j = m - 1; j >= 0; j--) {
                cur ++;
                cur = min(cur, mx[r][j]);
                mx[r][j] = cur;
            }
        }
        upds.clear();
        for(const auto &p : cor[i]) {
            int res = INF;
            for(int r = 0; r < n; r++) {
                res = min(res, mx[r][p.second] + abs(r - p.first));
            }
            fres[p.first][p.second] = res;
        }
        for(int r : row) {
            fill(mx[r], mx[r] + m, INF);
            vis[r] = false;
        }
        row.clear();
        for(const auto &p : cor[i]) {
            mx[p.first][p.second] = fres[p.first][p.second];
            if(!vis[p.first]) row.push_back(p.first), vis[p.first] = true;
        }
    }
    int res = INF;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) res = min(res, mx[i][j]);
    cout << res << endl;
}