#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXD = 105;

int N, M, Q;
pair<int, int> orig[MAXD][MAXD];
int val[MAXD][MAXD];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M >> Q;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            orig[r][c] = { r, c };
        }
    }

    int type, row, col;
    for (int q = 0; q < Q; q++) {
        cin >> type;

        if (type == 1) {
            cin >> row;
            row--;

            pair<int, int> felt = orig[row][0];
            for (int c = 0; c + 1 < M; c++)
                orig[row][c] = orig[row][c+1];
            orig[row][M-1] = felt;
        } else if (type == 2) {
            cin >> col;
            col--;

            pair<int, int> felt = orig[0][col];
            for (int r = 0; r + 1 < N; r++)
                orig[r][col] = orig[r+1][col];
            orig[N-1][col] = felt;
        } else {
            cin >> row >> col;
            row--; col--;

            pair<int, int> idx = orig[row][col];
            cin >> val[idx.first][idx.second];
        }
    }

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cout << val[r][c] << " ";
        }
        cout << "\n";
    }

    return 0;
}