#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1005;

const int DX[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int DY[] = {1, 1, 1, 0, -1, -1, -1, 0};

char s[MAXN][MAXN];
int n, m;
int res;
int used[MAXN][MAXN];
pair< int, int > q[MAXN * MAXN], black_q[MAXN * MAXN];

int
main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            used[i][j] = 0;
        }
    }
    res = 0;
    int timer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && s[i][j] == '0') {
                timer += 2;
                int qh = 0, qt = 0;
                used[i][j] = true;
                q[qt++] = make_pair(i, j);
                while (qh < qt) {
                    int cx = q[qh].first, cy = q[qh].second;
                    qh++;
                    for (int dir = 0; dir < 8; ++dir) {
                        int nx = cx + DX[dir], ny = cy + DY[dir];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m 
                                && s[nx][ny] == '0' && !used[nx][ny]) {
                            q[qt++] = make_pair(nx, ny);
                            used[nx][ny] = 1;
                        }
                    }
                }
                bool is_n_border = false;
                int cnt_black = 0;
                for (int it = 0; it < qh; ++it) {
                    int vx = q[it].first, vy = q[it].second;
                    if (vx == 0 || vy == 0 || vx == n - 1 || vy == m - 1) {
                        is_n_border = true;
                    }
                    for (int dir = 0; dir < 8; ++dir) {
                        int nx = vx + DX[dir], ny = vy + DY[dir];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m 
                                && s[nx][ny] == '1' && used[nx][ny] != timer) {
                            black_q[cnt_black++] = make_pair(nx, ny);
                            used[nx][ny] = timer;
                        }
                    }
                }
                ++timer;
                qh = qt = 0;
                if (cnt_black == 0 || is_n_border) {
                    continue;
                }
                int fx = black_q[0].first, fy = black_q[0].second;
                used[fx][fy] = timer;
                q[qt++] = black_q[0];
                while (qh < qt) {
                    int cx = q[qh].first, cy = q[qh].second;
                    qh++;
                    for (int dir = 1; dir < 8; dir += 2) {
                        int nx = cx + DX[dir], ny = cy + DY[dir];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m 
                                && s[nx][ny] == '1' && used[nx][ny] == timer - 1) {
                            used[nx][ny] = timer;
                            q[qt++] = make_pair(nx, ny);
                        }
                    }
                }
                int it = 0; 
                while (it < cnt_black && used[black_q[it].first][black_q[it].second] == timer) {
                    ++it;
                }
                bool is_num = true;
                for (it = 0; it < cnt_black; ++it) {
                    int cx = black_q[it].first, cy = black_q[it].second;
                    int cnt_neigh = 0;
                    for (int dir = 1; dir < 8; dir += 2) {
                        int nx = cx + DX[dir], ny = cy + DY[dir];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && used[nx][ny] == timer) {
                            ++cnt_neigh;
                        }
                    }
                    if (cnt_neigh != 2) {
                        is_num = false;
                    }
                }
                if (is_num && it == cnt_black) {
                    res = max(res, cnt_black);
                }
            }
        }
    }
    if (!res) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                if (s[i][j] == '1' && s[i][j + 1] == '1' && 
                        s[i + 1][j] == '1' && s[i + 1][j + 1] == '1') {
                    res = 4;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}