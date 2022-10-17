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

bool check(vi row) {
    int wrong = 0;
    for (int i = 0; i < row.size(); i++)
        if (row[i] != i+1)
            wrong++;
    return wrong <= 2;
}

void check(vvi grid) {
    bool all = true;
    for (int i = 0; i < grid.size(); i++)
        all &= check(grid[i]);
    if (all) {
        cout << "YES\n";
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vvi grid(N, vi(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> grid[i][j];

    check(grid);
    for (int a = 0; a < M; a++) {
        for (int b = a + 1; b < M; b++) {
            vvi copy = grid;
            for (int i = 0; i < N; i++) {
                swap(copy[i][a], copy[i][b]);
            }
            check(copy);
        }
    }

    cout << "NO\n";
    return 0;
}