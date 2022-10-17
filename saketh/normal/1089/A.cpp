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

const int MAXG = 6;
const int MAXV = 201;

int dp[MAXG][MAXG][MAXV][MAXV][2];
int br[MAXV][MAXV][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    memset(dp, 0xff, sizeof(dp));
    dp[0][0][0][0][0] = 0;
    dp[0][0][0][0][1] = 0;

    memset(br, 0x80, sizeof(br));

    auto record = [&](int g, int w, int a, int b, int ap, int bp) {
        if (dp[g][w][a][b][0] != -1) return;
        if (ap > a) return;
        if (bp > b) return;
        int pw = w - int(ap > bp);
        if (pw < 0 || pw == 3 || g-1-pw < 0 || g-1-pw == 3) return;
        if (dp[g-1][w - int(ap > bp)][a-ap][b-bp][0] == -1) return;

        dp[g][w][a][b][0] = ap;
        dp[g][w][a][b][1] = bp;
        if ((w == 3 || g - w == 3) && 2 * w - g > br[a][b][0]) {
            br[a][b][0] = 2 * w - g;
            br[a][b][1] = w;
        }
    };

    for (int g = 1; g <= 5; g++) {
        int win = g < 5 ? 25 : 15;
        for (int w = 0; w <= min(g, 3); w++) {
            for (int a = 0; a < MAXV; a++) {
                for (int b = 0; b < MAXV; b++) {
                    for (int winp = win; winp <= max(a, b); winp++) {
                        for (int losp = (winp > win) ? winp - 2 : 0; losp + 2 <= winp; losp++) {
                            record(g, w, a, b, winp, losp);
                            record(g, w, a, b, losp, winp);
                        }
                    }
                }
            }
        }
    }

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int a, b;
        cin >> a >> b;

        if (br[a][b][0] == 0x80808080) {
            cout << "Impossible\n";
        } else {
            int ow = br[a][b][1];
            int tw = -br[a][b][0] + ow;
            int g = ow + tw;
            cout << ow << ":" << tw << "\n";

            vector<pair<int, int>> scores;
            while (g) {
                int op = dp[g][ow][a][b][0];
                int tp = dp[g][ow][a][b][1];
                scores.emplace_back(op, tp);
                a -= op;
                b -= tp;
                g--;
                ow -= (op > tp);
            }

            reverse(all(scores));
            for (auto [op, tp] : scores) {
                cout << op << ":" << tp << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}