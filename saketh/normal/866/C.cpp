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
typedef vector<double> vd;
typedef vector<vd> vvd;

double dp[5001][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
    
    int N, R;
    cin >> N >> R;

    vi f(N), s(N);
    vd p(N);

    for (int i = 0; i < N; i++) {
        cin >> f[i] >> s[i];

        int P;
        cin >> P;
        p[i] = P / 100.;
    }

    double lo = 0, hi = 1e9;

    for (int iter = 0; iter < 80; iter++) {
        memset(dp, 0, sizeof(dp));

        double tr = (lo + hi ) / 2;
        dp[0][0] = tr;

        for (int t = R; t >= 0; t--) {
            for (int i = N - 1; i >= 0; i--) {
                double s1 = (t + f[i] <= R) ? dp[t + f[i]][i+1] : dp[0][0];
                double s2 = (t + s[i] <= R) ? dp[t + s[i]][i+1] : dp[0][0];

                dp[t][i] = min(dp[0][0], p[i] * (f[i] + s1) + (1 - p[i]) * (s[i] + s2));
            }
        }

        if (dp[0][0] < tr) {
            hi = tr;
        } else {
            lo = tr;
        }

        //cout << lo << " " << hi << endl;
    }

    cout << dp[0][0] << "\n";
    return 0;
}