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

    int N, M;
    cin >> N >> M;

    vvi grid(N, vi(M));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
            grid[i][j] = row[j] == '*';
    }

    vvi size(N, vi(M, INT_MAX));

    for (int rep = 0; rep < 2; rep++) {
        vi vert(M);
        for (int i = 0; i < N; i++) {
            int horiz = 0;
            for (int j = 0; j < M; j++) {
                if (grid[i][j]) {
                    vert[j]++;
                    horiz++;
                } else {
                    vert[j] = 0;
                    horiz = 0;
                }
                size[i][j] = min(size[i][j], max(0, min(vert[j], horiz) - 1));
            }
        }

        reverse(all(grid));
        for (auto &r : grid)
            reverse(all(r));

        reverse(all(size));
        for (auto &r : size)
            reverse(all(r));
    }

    int tot = 0;
    vvi made(N, vi(M));

    for (int rep = 0; rep < 2; rep++) {
        vi vert(M, -1);
        for (int i = 0; i < N; i++) {
            int horiz = -1;
            for (int j = 0; j < M; j++) {
                if (size[i][j]) {
                    horiz = max(horiz, j + size[i][j]);
                    vert[j] = max(vert[j], i + size[i][j]);
                    if (rep) tot++;
                }
                if (horiz >= j || vert[j] >= i) {
                    made[i][j] = 1;
                }
            }
        }

        reverse(all(size));
        for (auto &r : size)
            reverse(all(r));

        reverse(all(made));
        for (auto &r : made)
            reverse(all(r));
    }

    if (made == grid) {
        cout << tot << "\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (size[i][j])
                    cout << i + 1 << " " << j + 1 << " " << size[i][j] << "\n";
    } else cout << -1 << endl;

    return 0;
}