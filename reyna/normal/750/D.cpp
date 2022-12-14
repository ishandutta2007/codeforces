// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 330, mod = (int) 0;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int can[35][8][N][N], t[N], mark[N][N], res;
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int sx = N / 2, sy = N / 2;
    mark[sx][sy] = 1;
    can[0][0][sx][sy] = 1;
    for (int j = 0; j < n; ++j)
        cin >> t[j];
    t[0]--;
    for (int j = 0; j < n; ++j) {
        for (int d = 0; d < 8; ++d) {
            int dl = (d + 7) % 8, dr = (d + 1) % 8;
            for (int x = 0; x < N; ++x)
                for (int y = 0; y < N; ++y) {
                    int nx = x + dx[d] * t[j];
                    int ny = y + dy[d] * t[j];
                    if (can[j][d][x][y]) {
                        can[j + 1][dl][nx][ny] = can[j + 1][dr][nx][ny] = 1, mark[nx][ny] = 1;
                        for (int z = 0; z <= t[j]; ++z)
                            mark[x + dx[d] * z][y + dy[d] * z] = 1;
                    }
                }
        }
    }
    for (int j = 0; j < N; ++j)
        for (int i = 0; i < N; ++i)
            res += mark[i][j];
    cout << res << endl;
}