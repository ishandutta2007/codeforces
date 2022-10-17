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

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    string s;
    cin >> N >> s;
    N *= 2;
    M = s.size();

    vi fail(M + 1);
    for (int i = 1, p = 0; i < M; i++) {
        while (p > 0 && s[p] != s[i])
            p = fail[p];
        if (s[p] == s[i])
            p++;
        fail[i+1] = p;
    }

    int dp[N+1][M+1][N/2+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= N/2; k++) {
                for (char c : { '(', ')' }) {
                    int jp = j;
                    if (jp < M) {
                        while (jp > 0 && s[jp] != c)
                            jp = fail[jp];
                        if (s[jp] == c) jp++;
                    }

                    int kp = k + (c == '(' ? 1 : -1);
                    if (kp < 0 || kp > N/2) continue;

                    int &succ = dp[i+1][jp][kp];
                    succ = sum(succ, dp[i][j][k]);
                }
            }
        }
    }

    cout << dp[N][M][0] << "\n";
    return 0;
}