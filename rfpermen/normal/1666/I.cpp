#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const int N = 16;
const int INF = (int)1e9;

int scan(int x, int y) {
    printf("SCAN %d %d\n", x, y); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int dig(int x, int y) {
    printf("DIG %d %d\n", x, y); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int solve(const vector<int>& row, const vector<int>& col) {
    int found = dig(row[0], col[0]);
    if (found == 1) {
        found += dig(row[1], col[1]);
        return found;
    }

    // dig the other way
    found += dig(row[0], col[1]);
    found += dig(row[1], col[0]);
    return found;
}

int dat[N+5][N+5];

int main() {
    int t; scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        for (int i = 0; i < N + 3; i++) {
            for (int j = 0; j < N + 3; j++) {
                dat[i][j] = -INF;
            }
        }

        int n,m; scanf("%d %d", &n, &m);
        const int max_dist = n + m - 2;

        auto scan_and_mark = [&](int x, int y) {
            const int sum_dist = scan(x, y);

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    const int d = abs(x - i) + abs(y - j);

                    dat[i][j] += (max_dist + d <= sum_dist);
                    dat[i][j] += (d <= sum_dist && sum_dist < max_dist);
                }
            }
        };

        dat[1][1] = scan(1, 1);
        dat[n][m] = 2 * max_dist - dat[1][1];
        dat[1][m] = scan(1, m);
        dat[n][1] = 2 * max_dist - dat[1][m];

        // update
        for (int i = 2; i <= n; i++) {
            dat[i][1] = max(dat[i][1], dat[i-1][1] - 2);
        }
        for (int i = n - 1; i >= 1; i--) {
            dat[i][1] = max(dat[i][1], dat[i+1][1] - 2);
        }
        for (int j = 2; j <= m; j++) {
            dat[1][j] = max(dat[1][j], dat[1][j-1] - 2);
        }
        for (int j = m - 1; j >= 1; j--) {
            dat[1][j] = max(dat[1][j], dat[1][j+1] - 2);
        }

        // find min
        int pos_min_x = 1;
        for (int i = 1; i <= n; i++) {
            if (dat[i][1] < dat[pos_min_x][1]) {
                pos_min_x = i;
            }
        }

        int pos_min_y = 1;
        for (int j = 1; j <= m; j++) {
            if (dat[1][j] < dat[1][pos_min_y]) {
                pos_min_y = j;
            }
        }

        // ask
        const int ret_x = scan(pos_min_x, 1);
        const int ret_y = scan(1, pos_min_y);

        // find again
        vector<int> row;
        for (int i = 1; i <= n; i++) {
            if (dat[i][1] == ret_x) {
                row.push_back(i);
            }
        }

        vector<int> col;
        for (int j = 1; j <= m; j++) {
            if (dat[1][j] == ret_y) {
                col.push_back(j);
            }
        }

        // duplicate candidate if it is a must
        if ((int)row.size() == 1) {
            row.push_back(row[0]);
        }
        if ((int)col.size() == 1) {
            col.push_back(col[0]);
        }

        // try to dig
        if (solve(row, col) != 2) {
            printf("case %d\n", tc);
        }
    }
    return 0;
}