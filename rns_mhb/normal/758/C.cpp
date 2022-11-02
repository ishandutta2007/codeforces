#include <bits/stdc++.h>
using namespace std;

#define N 105
#define INF 1000000000000000000

typedef long long ll;
int n, m, x, y;
ll k, mx, mn, ans;
ll cnt[N][N];
int idx[20000], idy[20000];

int main() {
    scanf("%d %d %I64d %d %d", &n, &m, &k, &x, &y);
    if (n == 1) {
        mx = (k % m == 0) ? (k / m) : (k / m + 1);
        mn = (k % m == 0) ? (k / m) : (k / m);
        ans = (k % m == 0) ? mx : ((y <= k % m) ? mx : mn);
        printf("%I64d %I64d %I64d\n", mx, mn, ans);
        return 0;
    }
    ll mod = ((2 * n - 2) * m);
    ll q = k / mod;
    ll r = k % mod;
    if (n == 2) {
        if (r) {
            mx = q + 1, mn = q;
            ans = ((x - 1) * m + (y - 1) <= r - 1 ? mx : mn);
        }
        else {
            mx = mn = ans = q;
        }
        printf("%I64d %I64d %I64d\n", mx, mn, ans);
        return 0;
    }
    for (int i = 0; i < mod; i ++) {
        if (i <= m * n - 1) {
            idx[i] = i / m + 1;
            idy[i] = i % m + 1;
        }
        else {
            int ii = i - n * m;
            idx[i] = n - ii / m - 1;
            idy[i] = ii % m + 1;
        }
    }
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) {
        if (i == 1 || i == n) cnt[i][j] = q;
        else cnt[i][j] = 2 * q;
    }
    for (int i = 0; i < r; i ++) {
        cnt[idx[i]][idy[i]] ++;
    }
    mn = INF, mx = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) {
        mx = max(mx, cnt[i][j]);
        mn = min(mn, cnt[i][j]);
    }
    printf("%I64d %I64d %I64d\n", mx, mn, cnt[x][y]);
}