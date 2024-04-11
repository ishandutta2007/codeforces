#include <bits/stdc++.h>
#define y1 yy1
using namespace std;
const int N = (int)1e3 + 34;
const int M = 103;
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-14;
const ll P = 41;
const ll MD = (ll)1e9 + 9;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif // FIRE_MIND
}

int dp[N][2];
int n, p[N], s[N];
int a[N];

int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    for (int i = 0; i < n; i++)
        s[i + 1] = s[i] + a[n - i - 1];


    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 0; i < n; i++) {
        int v = a[n - i - 1];

        for (int turn = 0; turn < 2; turn++) {
            dp[i + 1][turn] = max(dp[i][turn], s[i] - dp[i][1 - turn] + v);
        }
    }

    cout << p[n] - dp[n][0] << " " << dp[n][0];

    return 0;
}