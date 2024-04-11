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

string build(string str, int inx) {
    stringstream ss;
    ss << str << " " << inx + 1;
    return ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    int low = INT_MAX;
    vvi grid(N, vi(M));

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> grid[r][c];
            low = min(low, grid[r][c]);
        }
    }

    vector<string> ops;

    for (int t = 0; t < low; t++) {
        if (N > M) {
            for (int c = 0; c < M; c++)
                ops.push_back(build("col", c));
        } else {
            for (int r = 0; r < N; r++)
                ops.push_back(build("row", r));
        }
    }

    for (int r = 0; r < N; r++) {
        vi &row = grid[r];

        int rem = INT_MAX;
        for (int &val : row) {
            val -= low;
            rem = min(rem, val);
        }

        for (int i = 0; i < rem; i++)
            ops.push_back(build("row", r));

        for (int &val : row)
            val -= rem;
    }

    for (int c = 0; c < M; c++) {
        vi vals;
        for (int r = 0; r < N; r++)
            vals.push_back(grid[r][c]);

        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());

        if (vals.size() != 1) {
            cout << -1 << endl;
            return 0;
        }

        for (int i = 0; i < vals[0]; i++)
            ops.push_back(build("col", c));
    }

    cout << ops.size() << "\n";
    for (string op : ops) cout << op << "\n";

    return 0;
}