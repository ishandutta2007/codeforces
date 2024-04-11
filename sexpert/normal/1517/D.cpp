#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 505;
const int INF = 1e9;
int n, m, k;
int hcost[MAXN][MAXN], vcost[MAXN][MAXN], dp[MAXN][MAXN], tdp[MAXN][MAXN];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m - 1; j++)
            cin >> hcost[i][j];

    for(int i = 1; i <= n - 1; i++)
        for(int j = 1; j <= m; j++)
            cin >> vcost[i][j];

    if(k % 2) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << "-1 ";
            }
            cout << '\n';
        }
        return 0;
    }

    k /= 2;

    for(int st = 1; st <= k; st++) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                tdp[i][j] = 0;

        for(int x = 1; x <= n; x++) {
            for(int y = 1; y <= m; y++) {
                tdp[x][y] = INF;
                for(int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 1 || ny < 1 || nx > n || ny > m)
                        continue;
                    if(nx == x - 1)
                        tdp[x][y] = min(tdp[x][y], dp[x - 1][y] + vcost[x - 1][y]);
                    if(nx == x + 1)
                        tdp[x][y] = min(tdp[x][y], dp[x + 1][y] + vcost[x][y]);
                    if(ny == y - 1)
                        tdp[x][y] = min(tdp[x][y], dp[x][y - 1] + hcost[x][y - 1]);
                    if(ny == y + 1)
                        tdp[x][y] = min(tdp[x][y], dp[x][y + 1] + hcost[x][y]);
                }
            }
        }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                dp[i][j] = tdp[i][j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << 2 * dp[i][j] << " ";
        }
        cout << '\n';
    }
}