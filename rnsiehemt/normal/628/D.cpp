#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const ll Mod = 1000*1000*1000+7;

int N, dd;
ll M;
ll dp[2005][2005][2][2];
char a[2005], b[2005];
ll val[2005];

void add(ll &a, ll b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

int main()
{
    scanf("%lld%d %s %s", &M, &dd, a, b);
    N = strlen(a);
    for (int i = 0; i < N; i++) {
        a[i] -= '0';
        b[i] -= '0';
    }
    val[N-1] = 1;
    for (int i = N-2; i >= 0; i--) {
        val[i] = (val[i+1] * 10) % M;
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i < N; i++) {
        if (i%2 == 1) {
            int d = dd;
            for (int m = 0; m < M; m++) {
                int newm = (m + d * val[i]) % M;
                add(dp[i+1][newm][1][1], dp[i][m][1][1]);
                if (d == b[i]) {
                    add(dp[i+1][newm][1][0], dp[i][m][1][0]);
                } else if (d < b[i]) {
                    add(dp[i+1][newm][1][1], dp[i][m][1][0]);
                }
                if (d == a[i]) {
                    add(dp[i+1][newm][0][1], dp[i][m][0][1]);
                } else if (d > a[i]) {
                    add(dp[i+1][newm][1][1], dp[i][m][0][1]);
                }
                if (d == a[i] && d == b[i]) {
                    add(dp[i+1][newm][0][0], dp[i][m][0][0]);
                } else if (d == a[i] && d < b[i]) {
                    add(dp[i+1][newm][0][1], dp[i][m][0][0]);
                } else if (d > a[i] && d == b[i]) {
                    add(dp[i+1][newm][1][0], dp[i][m][0][0]);
                } else if (d > a[i] && d < b[i]) {
                    add(dp[i+1][newm][1][1], dp[i][m][0][0]);
                }
            }
        } else {
            for (int d = 0; d < 10; d++) if (d != dd) {
                for (int m = 0; m < M; m++) {
                    int newm = (m + d * val[i]) % M;
                    add(dp[i+1][newm][1][1], dp[i][m][1][1]);
                    if (d == b[i]) {
                        add(dp[i+1][newm][1][0], dp[i][m][1][0]);
                    } else if (d < b[i]) {
                        add(dp[i+1][newm][1][1], dp[i][m][1][0]);
                    }
                    if (d == a[i]) {
                        add(dp[i+1][newm][0][1], dp[i][m][0][1]);
                    } else if (d > a[i]) {
                        add(dp[i+1][newm][1][1], dp[i][m][0][1]);
                    }
                    if (d == a[i] && d == b[i]) {
                        add(dp[i+1][newm][0][0], dp[i][m][0][0]);
                    } else if (d == a[i] && d < b[i]) {
                        add(dp[i+1][newm][0][1], dp[i][m][0][0]);
                    } else if (d > a[i] && d == b[i]) {
                        add(dp[i+1][newm][1][0], dp[i][m][0][0]);
                    } else if (d > a[i] && d < b[i]) {
                        add(dp[i+1][newm][1][1], dp[i][m][0][0]);
                    }
                }
            }
        }
    }
    ll ans = (dp[N][0][0][0] + dp[N][0][0][1] + dp[N][0][1][0] + dp[N][0][1][1]) % Mod;
    printf("%lld\n", ans);
}