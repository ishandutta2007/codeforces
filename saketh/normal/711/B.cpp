#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }

    vvll grid(N, vll(N));
    vll row(N), col(N);

    int zi, zj;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];

            row[i] += grid[i][j];
            col[j] += grid[i][j];

            if (grid[i][j] == 0)
                zi = i, zj = j;
        }

    bool poss = true;
    int nzi = !zi, nzj = !zj;

    for (int i = 0; i < N; i++) {
        if (i != zi) poss &= row[i] == row[nzi];
        if (i != zj) poss &= col[i] == col[nzj];
    }

    ll row_add = row[nzi] - row[zi];
    ll col_add = col[nzj] - col[zj];

    if (poss && row_add == col_add && row_add > 0 && row_add <= 1e18) {
        ll ans = row_add;
        grid[zi][zj] = ans;

        ll dsum1 = 0, dsum2 = 0;

        for (int i = 0; i < N; i++) {
            dsum1 += grid[i][i];
            dsum2 += grid[i][N-1-i];
        }

        if (dsum1 == dsum2 && dsum1 == row[nzi]) {
            cout << ans << "\n";
            return 0;
        }
    } 

    cout << -1 << "\n";
    return 0;
}