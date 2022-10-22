#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAXN = 260;
char f[MAXN][MAXN];
int d[MAXN][MAXN];
int used[MAXN][MAXN];
int rev;
int ans[MAXN][MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    rev = 0;
    int n, m, q, p;
    scanf("%d%d%d%d", &n, &m, &q, &p);
    for (int i = 0; i < n; i++) {
        scanf("%s", f[i]);
    }

    for (int sx = 0; sx < n; sx++) {
        for (int sy = 0; sy < m; sy++) {
            if ('A' <= f[sx][sy] && f[sx][sy] <= 'Z') {
                rev++;
                deque<pair<int, int>> qq;
                d[sx][sy] = q * (f[sx][sy] - 'A' + 1);
                used[sx][sy] = rev;
                ans[sx][sy] += d[sx][sy];
                qq.push_back({sx, sy});
                while (!qq.empty()) {
                    auto u = qq.front();
                    qq.pop_front();
                    for (int dd = 0; dd < 4; dd++) {
                        int x = u.first + dx[dd];
                        int y = u.second + dy[dd];
                        if (0 <= x && x < n && 0 <= y && y < m) {
                            if (f[x][y] != '*' && used[x][y] < rev) {
                                used[x][y] = rev;
                                d[x][y] = d[u.first][u.second] / 2;
                                ans[x][y] += d[x][y];
                                if (d[x][y] > 0) {
                                    qq.push_back({x, y});
                                }
                            }
                        }
                    }
                }

//                for (int i = 0; i < n; i++) {
//                    for (int j = 0; j < m; j++) {
//                        cout << ans[i][j] << " ";
//                    }
//                    cout << endl;
//                }
//                cout << endl;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
//            cout << ans[i][j] << " ";
            if (ans[i][j] > p) {
                res++;
            }
        }
//        cout << endl;
    }

    cout << res << endl;

    return 0;
}