#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vvi arc(N, vi(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arc[i][j];
        }
    }

    char grid[3][3 * N + 3][3 * N];
    memset(grid, '#', sizeof(grid));

    for (int i = 0; i < N; i++) {
        for (int x = 0; x < 3 * N; x++)
            grid[2][3 * i + 1][x] = '.';
        for (int y = 0; y < 3 * N + 3; y++)
            grid[0][y][3 * i + 1] = '.';

        grid[2][3 * i + 1][0] = '1' + i;

        grid[2][3 * i + 2][3 * i + 2] = '.';
        grid[1][3 * i + 2][3 * i + 2] = '.';

        grid[1][3 * i + 3][3 * i + 2] = '.';
        grid[0][3 * i + 3][3 * i + 2] = '.';
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arc[i][j]) {
                grid[2][3 * i + 2][3 * j + 2] = '.';
                grid[1][3 * i + 2][3 * j + 2] = '.';
                grid[0][3 * i + 2][3 * j + 2] = '.';
            }
        }
    }

    cout << 3 * N << " " << 3 * N + 3 << " " << 3 << "\n";
    for (int z = 2; z >= 0; z--) {
        for (int y = 0; y < 3 * N + 3; y++) {
            for (int x = 0; x < 3 * N; x++)
                cout << grid[z][y][x];
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}