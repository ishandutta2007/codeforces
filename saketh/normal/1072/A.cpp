#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int W, H, K;
    cin >> W >> H >> K;

    vvi grid(H, vi(W));

    for (int k = 0; k < K; k++) {
        int r1 = 2 * k, r2 = H-1 - 2 * k;
        int c1 = 2 * k, c2 = W-1 - 2 * k;

        for (int c = c1; c <= c2; c++) {
            grid[r1][c] = 1;
            grid[r2][c] = 1;
        }

        for (int r = r1; r <= r2; r++) {
            grid[r][c1] = 1;
            grid[r][c2] = 1;
        }
    }

    int ans = 0;
    for (auto &row : grid)
        for (int v : row)
            ans += v;
    cout << ans << endl;

    return 0;
}