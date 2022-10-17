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

const int MAXN = 101;
const int MAXS = 1001;
double mult[MAXN];
double dp[2][MAXN][MAXS];

void solve() {
    int N;
    double C, T;
    cin >> N >> C >> T;

    vector<array<int, 2>> prob(N);
    for (int i = 0; i < N; i++) {
        cin >> prob[i][0] >> prob[i][1];
    }
    sort(all(prob));
    reverse(all(prob));

    for (int i = 0; i < MAXN; i++) {
        for (int ts = 0; ts < MAXS; ts++) {
            dp[0][i][ts] = DBL_MAX;
        }
    }
    dp[0][0][0] = 0;

    bool x = false;
    for (int i = 0; i < N; i++) {
        int diff = prob[i][0];
        int valu = prob[i][1];
        memcpy(dp[!x], dp[x], sizeof(dp[x]));

        for (int cs = 0; cs <= i; cs++) {
            for (int pt = 0; pt + valu < MAXS; pt++) {
                if (dp[x][cs][pt] == DBL_MAX) continue;
                double &targ = dp[!x][cs+1][pt+valu];
                targ = min(targ, dp[x][cs][pt] + mult[cs] * diff);
            }
        }

        x = !x;
    }

    int ans = 0;
    for (int cs = 1; cs <= N; cs++) {
        for (int pt = 0; pt < MAXS; pt++) {
            if (dp[x][cs][pt] == DBL_MAX) continue;
            const double V = dp[x][cs][pt];

            if (V < T - 10 * cs + 1e-9) {
                ans = max(ans, pt);
                continue;
            }

            if (C > 0) {
                double tlo = 0, thi = T;
                for (int rep = 0; rep < 100; rep++) {
                    double c1 = (2 * tlo + thi) / 3;
                    double c2 = (tlo + 2 * thi) / 3;

                    double t1 = c1 + 10 * cs + V / (C * c1 + 1.0);
                    double t2 = c2 + 10 * cs + V / (C * c2 + 1.0);

                    if (min(t1, t2) < T + 1e-9) {
                        ans = max(ans, pt);
                        break;
                    } else if (t1 < t2) {
                        thi = c2;
                    } else {
                        tlo = c1;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    mult[0] = 1/.9;
    for (int i = 1; i < MAXN; i++)
        mult[i] = mult[i-1]/.9;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }

    return 0;
}