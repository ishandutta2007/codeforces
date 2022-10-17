#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int T, W, K;

    for (cin >> T; T; T--) {
        cin >> W >> K;

        string rows[3];

        for (int i = 0; i < 3; i++) {
            cin >> rows[i];
            rows[i] += "...";
        }

        bool can[2][3][W+3];
        memset(can, 0, sizeof(can));

        for (int i = 0; i < 3; i++) {
            if (rows[i][0] == 's')
                can[0][i][0] = true;
        }

        int x = 0;
        bool succ = false;

        for (int t = 0; t < 500; t++) {
            memset(can[x^1], 0, sizeof(can[x^1]));

            for (int r = 0; r < 3; r++)
                for (int c = 0; c < W; c++) {
                    if (!can[x][r][c]) continue;

                    for (int dy = -1; dy <= 1; dy++) {
                        if (rows[r][c+1] != '.') continue;
                        if (r + dy < 0 || r + dy > 2) continue;
                        if (rows[r+dy][c+1] != '.') continue;
                        if (rows[r+dy][c+2] != '.') continue;
                        if (rows[r+dy][c+3] != '.') continue;

                        can[x^1][r+dy][c+3] = true;
                        if (c + 3 >= W) succ = true;
                    }
                }

            x ^= 1;
        }

        cout << (succ ? "YES" : "NO") << "\n";
    }
}