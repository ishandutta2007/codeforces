#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;
const int N = (int)1e5 + 34;
const int INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;
const ll p1 = 997;
const ll p2 = 2017;

void addm(int &a, int b) {
    a += b;
    if (a >= md)
        a -= md;
}

int a[100];

int dp[1 << 20][77];
int x;
int f[100];

int main() {
    init();
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    a[n] = 1;

    for (int i = 0; i < n; i++) {
        f[i] = i;
        while (a[f[i]] == 0)
            f[i]++;
    }

    int st;
    dp[0][n] = 1;
    for (int len = 0; len < n; len++) {
        //cerr << len << "\n";
        dp[0][len] = 1;
        st = f[len];
        for (int mask = 0; mask < (1 << 20); mask++) {
            if (dp[mask][len] == 0) continue;
            x = 0;
            for (int i = st; i < n && i < st + 5; i++) {
                x = ((x << 1) | a[i]);
                if (x > 0 && x <= 20) {
                    addm(dp[mask | (1 << (x - 1))][i + 1], dp[mask][len]);
                }
            }
        }
    }

    int ans = 0;
    for (int len = 1; len <= n; len++)
    for (int mask = 1; mask < (1 << 20); mask++) {
        x = dp[mask][len];
        if (x && (mask & (mask + 1)) == 0)
            addm(ans, dp[mask][len]);
    }

    cout << ans;

    return 0;
}