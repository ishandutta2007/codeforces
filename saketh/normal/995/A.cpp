#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vvi grid(4, vi(N));

    vector<array<int, 3>> moves;
    int ex = -1, ey = -1;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < N; j++) {
            if ((i == 1) || (i == 2)) {
                if (grid[i][j] != 0 && grid[i][j] == grid[i^1][j]) {
                    moves.push_back({ grid[i][j], i^1, j });
                    grid[i][j] = 0;
                    K--;
                }
                if (grid[i][j] == 0) {
                    ex = i;
                    ey = j;
                }
            }
        }
    }

    if (ey == -1 && K > 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<array<int, 2>> locs;
    for (int i = 0; i < N; i++) {
        locs.push_back({ 1, i });
    }
    for (int i = N - 1; i >= 0; i--) {
        locs.push_back({ 2, i });
    }

    array<int, 2> empty = { ex, ey };
    int i = 0;
    while (locs[i] != empty) i++;

    while (K) {
        int ii = (i + 1) % locs.size();

        int &nbr = grid[locs[ii][0]][locs[ii][1]];
        if (nbr != 0) {
            int x = locs[i][0];
            int y = locs[i][1];

            moves.push_back({ nbr, x, y });
            grid[x][y] = nbr;
            nbr = 0;

            if (grid[x][y] == grid[x^1][y]) {
                moves.push_back({grid[x][y], x^1, y});
                grid[x][y] = 0;
                K--;
            }
        }

        i = ii;
    }

    cout << moves.size() << "\n";
    for (auto a : moves) {
        cout << a[0] << " " << a[1] + 1 << " " << a[2] + 1 << "\n";
    }

    return 0;
}