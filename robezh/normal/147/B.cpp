#include <bits/stdc++.h>
using namespace std;

const int N = 305, INF = (int)1e9 + 50, LOG = 9;

int n, m;
int dis[LOG][N][N], dp[2][N][N];


bool check(int res) {
    int nw = 1, la = 0;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < n; i++) dp[nw][i][i] = 0;
    for(int t = 0; t < LOG; t++) {
        if(!((res >> t) & 1)) continue;
        swap(nw, la);
        memset(dp[nw], 0x3f, sizeof(dp[nw]));
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dp[nw][i][j] = min(dp[nw][i][j], dp[la][i][k] + dis[t][k][j]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) if(dp[nw][i][i] < 0) return true;
    return false;
}

int main() {
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < n; i++) dis[0][i][i] = 0;
    for(int i = 0; i < m; i++) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        u--, v--;
        dis[0][u][v] = -c1;
        dis[0][v][u] = -c2;
    }

    for(int t = 1; t < LOG; t++) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dis[t][i][j] = min(dis[t][i][j], dis[t - 1][i][k] + dis[t - 1][k][j]);
                }
            }
        }
    }

    int l = 0, r = n + 1, mid;
//    for(int i = 0; i < n; i++) cout << check(i) << " ";
//    cout << endl;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(r == n + 1) cout << 0 << endl;
    else cout << r << endl;

}