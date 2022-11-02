#include <bits/stdc++.h>

#define sz(x) (int((x).size()))

const int maxn = 2005;
const int Mod = 998244353;
const long long Modll = 998244353ll;

int T, n;
std::vector<int> odd, even;
int dp[2][maxn][11];

void addto(int &a, int b) {
    a += b;
    if (a >= Mod) a -= Mod;
}

int times(long long a, long long b) {
    return (a*b) % Modll;
}

void handle(int a) {
    int l = 0, m = 0, p = 1;
    while (a) {
        m = (m + (a % 10) * p + 11) % 11;
        p = -p;
        l++;
        a /= 10;
    }
    if (l%2) odd.push_back(m);
    else even.push_back(m);
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &n);
        odd.clear();
        even.clear();
        for (int i = 0; i < n; i++) {
            int a;
            scanf("%d", &a);
            handle(a);
        }

        int cur = 0, prev = 1;
        for (int j = 0; j <= 0; j++) for (int k = 0; k < 11; k++)
            dp[cur][j][k] = 0;
        dp[cur][0][0] = 1;
        for (int i = 0; i < sz(odd); i++) {
            std::swap(cur, prev);
            for (int j = 0; j <= i+1; j++) for (int k = 0; k < 11; k++)
                dp[cur][j][k] = 0;
            for (int j = 0; j <= i; j++) {
                int evenpos = sz(odd) - sz(odd) / 2 - (i - j);
                int oddpos = sz(odd) / 2 - j;
                for (int k = 0; k < 11; k++) {
                    if (evenpos > 0) {
                        addto(dp[cur][j][(k + odd[i]) % 11], times(dp[prev][j][k], evenpos));
                    }
                    if (oddpos > 0) {
                        addto(dp[cur][j+1][(k + 11 - odd[i]) % 11], times(dp[prev][j][k], oddpos));
                    }
                }
            }
            /*for (int j = 0; j <= i+1; j++) for (int k = 0; k < 11; k++)
                printf("dp[cur][%d][%d] = %d\n", j, k, dp[cur][j][k]);*/
        }
        std::swap(cur, prev);
        for (int j = 0; j <= sz(odd); j++) for (int k = 0; k < 11; k++) {
            dp[cur][j][k] = 0;
        }
        for (int j = 0; j <= sz(odd); j++) for (int k = 0; k < 11; k++) {
            addto(dp[cur][0][k], dp[prev][j][k]);
        }
        for (int i = 0; i < sz(even); i++) {
            std::swap(cur, prev);
            for (int j = 0; j <= i+1; j++) for (int k = 0; k < 11; k++) {
                dp[cur][j][k] = 0;
            }
            for (int j = 0; j <= i; j++) {
                int oddpos = j + (sz(odd) + 1) / 2;
                int evenpos = i-j + sz(odd) / 2 + 1;
                for (int k = 0; k < 11; k++) {
                    addto(dp[cur][j][(k + even[i]) % 11], times(dp[prev][j][k], evenpos));
                    addto(dp[cur][j+1][(k + 11 - even[i]) % 11], times(dp[prev][j][k], oddpos));
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= sz(even); j++) {
            addto(ans, dp[cur][j][0]);
        }
        printf("%d\n", ans);
    }
}