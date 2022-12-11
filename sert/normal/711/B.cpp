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

const int N = 1e3 + 34;

ll n, x, m, a[N][N], y;
ll d1, d2, r[N], c[N], sum, sum0;

void fail() {
    cout << "-1\n";
    exit(0);
}

int main() {
    init();

    scanf("%I64d", &n);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        scanf("%I64d", a[i] + j);
        if (a[i][j] == 0) {
            x = j;
            y = i;
        }
    }

    int yy = !y;
    for (int j = 0; j < n; j++)
        sum += a[yy][j];
    for (int j = 0; j < n; j++)
        sum0 += a[y][j];

    a[y][x] = sum - sum0;

    for (int i = 0; i < n; i++) {
        d1 += a[i][i];
        d2 += a[i][n - i - 1];
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
        r[i] += a[i][j];
        c[j] += a[i][j];
    }

    if (d1 != sum || d2 != sum)
        fail();
    for (int i = 0; i < n; i++)
        if (r[i] != sum || c[i] != sum)
            fail();

if (n == 1) cout << 1; else cout << (a[y][x] <= 0 ? -1 : a[y][x]);

    return 0;
}