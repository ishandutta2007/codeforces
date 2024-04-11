#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N 100100
int n, dp[N], tp[N];
ll a[N], b[N];

inline void chkmin(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d", &n); ll mx = 0;
    for (int i = 1; i <= n; i ++) scanf("%I64d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) a[i] = a[n] - a[i], mx = max(mx, a[i]);
    for (int i = 1; i <= n; i ++) dp[i] = 1e9;
    for (int bit = 0; bit <= __lg(mx) + 1; bit ++) {
        for (int i = 0; i <= n; i ++) tp[i] = dp[i], dp[i] = 1e9;
        int one = 0, zero = 0;
        for (int i = 1; i <= n; i ++) {
            if (a[i] >> bit & 1) one ++, b[one] = a[i];
            else b[n-zero] = a[i], zero ++;
        }
        reverse(b + one + 1, b + n + 1);
        int zero_carry = 0, one_carry = one;
        for (int i = 0; i <= n; i ++) {
            if (i) {
                if (a[i] >> bit & 1) one --, zero ++, zero_carry ++;
                else zero --, one ++, one_carry ++;
            }
            chkmin(dp[zero_carry], tp[i] + one);
            chkmin(dp[one_carry], tp[i] + zero);
        }
        swap(a, b);
    }
    printf("%d\n", dp[0]);
}