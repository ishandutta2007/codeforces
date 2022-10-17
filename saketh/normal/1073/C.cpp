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

bool can_do(int tx, int ty, int sx, int sy, int sl, int x, int y) {
    int rx = tx - sx;
    int ry = ty - sy;

    int nx = x - rx;
    int ny = y - ry;

    int moves = abs(nx) + abs(ny);
    if (moves > sl) return false;
    return (moves % 2) == (sl % 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    string ops;
    cin >> ops;

    int x, y;
    cin >> x >> y;

    int tx = 0, ty = 0;
    for (char c : ops) {
        if (c == 'U') ty++;
        else if (c == 'D') ty--;
        else if (c == 'R') tx++;
        else tx--;
    }

    int ans = INT_MAX;

    int j = 0, sx = 0, sy = 0;
    for (int i = 0; i < N; ) {
        j = max(j, i);
        while (j <= N && !can_do(tx, ty, sx, sy, j-i, x, y)) {
            if (j == N) {
                j = -1;
                break;
            } else {
                if (ops[j] == 'U') sy++;
                else if (ops[j] == 'D') sy--;
                else if (ops[j] == 'R') sx++;
                else sx--;
                j++;
            }
        }

        if (j == -1) break;
        ans = min(ans, j-i);

        if (ops[i] == 'U') sy--;
        else if (ops[i] == 'D') sy++;
        else if (ops[i] == 'R') sx--;
        else sx++;
        i++;
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return 0;
}