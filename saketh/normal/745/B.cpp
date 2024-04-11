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

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    int r1 = INT_MAX, r2 = -1;
    int c1 = INT_MAX, c2 = -1;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (grid[r][c] == 'X') {
                r1 = min(r1, r);
                r2 = max(r2, r);
                c1 = min(c1, c);
                c2 = max(c2, c);
            }
        }
    }

    bool ok = true;
    for (int r = r1; r <= r2; r++)
        for (int c = c1; c <= c2; c++)
            if (grid[r][c] != 'X')
                ok = false;

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}