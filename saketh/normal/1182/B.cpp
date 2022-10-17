#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W;
    cin >> H >> W;

    vector<string> grid(H + 2, string(W + 2, '.'));
    for (int r = 1; r <= H; r++)
        for (int c = 1; c <= W; c++)
            cin >> grid[r][c];

    int cr = -1, cc = -1, tot = 0;
    for (int r = 1; r <= H; r++) {
        for (int c = 1; c <= W; c++) {
            if (grid[r][c] == '*') tot++;
            else continue;

            int nbr = 0;
            nbr += grid[r-1][c] == '*';
            nbr += grid[r][c-1] == '*';
            nbr += grid[r+1][c] == '*';
            nbr += grid[r][c+1] == '*';
            if (nbr == 4) {
                if (cr != -1) { cout << "NO\n"; return 0; }
                cr = r; cc = c;
            }
        }
    }
    if (cr == -1) { cout << "NO\n"; return 0; }

    int up = 1;
    while (grid[cr-up][cc] == '*') up++;
    int down = 1;
    while (grid[cr+down][cc] == '*') down++;
    int left = 1;
    while (grid[cr][cc-left] == '*') left++;
    int right = 1;
    while (grid[cr][cc+right] == '*') right++;

    bool good = (up + down + left + right - 4 + 1) == tot;
    cout << (good ? "YES\n" : "NO\n");

    return 0;
}