#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

ld p[5005], q[5005], dp[5005][5005];
int n, T, t[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> T;
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> t[i];
        p[i] /= 100.0;
        q[i] = 1.0 - p[i];
    }
    for(int t = 0; t <= T; t++)
        dp[n][t] = n;
    for(int m = 0; m < n; m++)
        dp[m][0] = m;

    for(int N = n - 1; N >= 0; N--) {
        if(N < n) {
            ld qq = 1, qti = 1, qqq = q[N];
            for(int i = 0; i < t[N] - 1; i++){
                qq *= q[N];
                qqq *= q[N];
            }
            ld window = dp[N + 1][0];
            for(int ti = 1; ti <= T; ti++) {
                qti *= q[N];
                //cout << window << " " << qq << endl;
                dp[N][ti] = window * p[N];
                if(ti - t[N] >= 0) dp[N][ti] += qqq * dp[N + 1][ti - t[N]];
                else dp[N][ti] += qti * dp[N][0];
                if(ti - t[N] >= 0) window -= qq*dp[N + 1][ti - t[N]];
                window *= q[N];
                //cout << window << endl;
                window += dp[N + 1][ti];
                //cout << "dp(" << N << ", " << ti << ") = " << dp[N][ti] << endl;
            }
        }
    }

    cout << fixed << setprecision(20) << dp[0][T] << endl;
}