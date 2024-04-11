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


const ll md = (int)1e9 + 7;
const int N = 5002;

void mda(int &a, int b) {
    a += b;
    if (a >= md)
        a -= md;
}

int d[N], dp[N][30];
int lst[N][30];
int z, n, x, y;

int c[N][N];

int main() {
    init();

    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % md;
        }
    }

    string s;
    cin >> n >> s;

    d[0] = 1;

    for (int i = 0; i < n; i++) {
        z = s[i] - 'a';
        for (int len = i; len >= 0; len--) {
            x = (d[len] - dp[len][z] + md) % md;
            y = x;
            x = (x - lst[len][z] + md) % md;
            lst[len][z] = y;
            mda(d[len + 1], x);
            mda(dp[len + 1][z], x);
        }
    }

    ll ans = 0, t1, t2;

    for (int len = 1; len <= n; len++)
    for (int z = 0; z < 26; z++) {
        if (dp[len][z] == 0) continue;
        t1 = dp[len][z];
        t2 = c[n - 1][len - 1];
        ans = (ans + t1 * t2) % md;
    }

    printf("%I64d\n", ans);

    return 0;
}