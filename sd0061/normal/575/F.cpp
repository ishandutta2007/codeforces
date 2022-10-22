#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 10005;
int l[N], r[N], b[N];
typedef long long LL;

LL f[2][N];

int gett(int x, int m) {
    return lower_bound(b + 1, b + 1 + m, x) - b;
}

LL solve(int l, int r, int x) {
    if (x < l) return l - x;
    if (x > r) return x - r;
    return 0;
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    int m = 0;
    b[++m] = x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        b[++m] = l[i];
        b[++m] = r[i];
    }
    sort(b + 1, b + 1 + m);
    m = unique(b + 1, b + 1 + m) - (b + 1);
    for (int i = 1; i <= n; ++i) {
        //l[i] = gett(l[i], m);
        //r[i] = gett(r[i], m);
    }
    x = gett(x, m);
    memset(f, 63, sizeof(f));
    int cur = 0, nex = 1;
    f[cur][x] = 0;
    for (int i = 1; i <= n; ++i) {
        LL mn = 1LL << 50;
        for (int j = 1; j <= m; ++j) {
            mn = min(f[cur][j] - b[j], mn);
            f[nex][j] = mn + b[j] + solve(l[i], r[i], b[j]);
        }
        mn = 1LL << 50;
        for (int j = m; j > 0; --j) {
            mn = min(f[cur][j] + b[j], mn);
            f[nex][j] = min(f[nex][j], mn - b[j] + solve(l[i], r[i], b[j]));
        }
        swap(cur, nex);
    }
    LL ans = 1LL << 50;
    //cout << solve(l[])
    for (int i = 1; i <= m; ++i)
        ans = min(ans, f[cur][i]);
    cout << ans << endl;
    return 0;
}