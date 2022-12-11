#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 5003;
ll sum;
int dp[N][N];
int kol[N];
int n, k, a, b, d, l, r;
ll p[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; i++)
        kol[abs(i - b)]++;
    for (int i = 0; i < n; i++)
        dp[a][0] = 1;

    for (int i = 1; i <= k; i++) {
        p[0] = 0;
        for (int j = 1; j <= n; j++) {
            p[j] = (p[j - 1] + dp[j][i - 1]) % md;
        }

        for (int j = 1; j <= n; j++) {
            if (j == b) continue;
            if (j < b) {
                l = 0;
                r = (j + b - 1) / 2;
            } else {
                l = (j + b) / 2 + 1;
                r = n;
            }
            dp[j][i] = (p[r] - p[l - 1] - dp[j][i - 1] + md * 2) % md;
        }
    }
    sum = 0;
    for (int i = 1; i <= n; i++)
        sum = (sum + dp[i][k]) % md;
    cout << sum;


    return 0;
}