#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

const int INF = 0x7f7f7f7f;

// used, first unplaced 0, first unplaced 1, first unplaced 2, last used value
int dp[2][76][76][76][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    memset(dp, 0x7f, sizeof(dp));

    int N;
    string str;
    cin >> N >> str;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        if (str[i] == 'V') vals[i] = 0;
        else if (str[i] == 'K') vals[i] = 1;
        else vals[i] = 2;
    }

    array<int, 3> nxt = { N, N, N };
    vi succ(N);

    vvi bef(N + 1, vi(3, 0)); // bef[i][j] = # of instances of j appearing at or before i
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= min(i, N - 1); j++)
            bef[i][vals[j]]++;
        WATCHC(bef[i]);
    }
    bef[N][0]++;
    bef[N][1]++;
    bef[N][2]++;

    for (int i = N - 1; i >= 0; i--) {
        succ[i] = nxt[vals[i]];
        nxt[vals[i]] = i;
    }

    WATCHC(succ);

    dp[0][nxt[0]][nxt[1]][nxt[2]][2] = 0;

    int w = 0;
    for (int l = 0; l < N; l++) {
        memset(dp[!w], 0x7f, sizeof(dp[!w]));

        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++) {
                for (int z = 0; z <= N; z++) {
                    for (int v = 0; v < 3; v++) {
                        const int &t = dp[w][x][y][z][v];
                        if (t == INF) continue;

                        TRACE(cout << l << " " << x << " " << y << " " << z << " " << v << " " << t << endl;)

                        if (x != N) {
                            // put a V next
                            int &s = dp[!w][succ[x]][y][z][0];
                            s = min(s, t 
                                    + max(0, bef[x][1] - bef[y][1] + 1)
                                    + max(0, bef[x][2] - bef[z][2] + 1));
                        }

                        if (y != N && v != 0) {
                            // put a K
                            int &s = dp[!w][x][succ[y]][z][1];
                            s = min(s, t 
                                    + max(0, bef[y][0] - bef[x][0] + 1)
                                    + max(0, bef[y][2] - bef[z][2] + 1));

                            /*cout << "Cost to put a K here is " <<
                                    max(0, bef[y][0] - bef[x][0] + 1) << " " <<
                                    max(0, bef[y][2] - bef[z][2] + 1) << endl;*/
                        }

                        if (z != N) {
                            // put a neutral next
                            int &s = dp[!w][x][y][succ[z]][2];
                            s = min(s, t 
                                    + max(0, bef[z][0] - bef[x][0] + 1)
                                    + max(0, bef[z][1] - bef[y][1] + 1));
                        }
                    }
                }
            }
        }

        w = !w;
    }

    int ans = INF;
    for (int l = 0; l < 3; l++)
        ans = min(ans, dp[w][N][N][N][l]);
    cout << ans << endl;

    return 0;
}