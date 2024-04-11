#include <bits/stdc++.h>
using namespace std;

#define N 1000100
int n, a[N], b[N], fac[N], rfac[N], ri[N];
const int mod = 998244353;

inline int C(int n, int m) {
    if (n < m) return 0;
    return 1ll * rfac[m] * rfac[n-m] % mod * fac[n] % mod;
}

int main() {
    fac[0] = rfac[0] = ri[1] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = 1ll * i * fac[i-1] % mod;
        if (i > 1) ri[i] = 1ll * (mod - mod / i) * ri[mod%i] % mod;
        rfac[i] = 1ll * ri[i] * rfac[i-1] % mod;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int k;
    for (k = 1; k <= n; k ++) if (a[k] < k - 1) break;
    if (k <= n) {
        k --;
        int rlt = 0;
        for (int i = 0, j = 1; i < k; i ++) {
            while (a[j] < i) j ++;
            rlt += C(i - j + n, n - 1);
            if (rlt >= mod) rlt -= mod;
        }
        printf("%d\n", rlt);
    }
    else {
        int sum = 0, rlt = 0;
        for (int i = 1; i <= n; i ++) b[a[i]%n] ++, sum += a[i] / n;
        for (int i = 0; i < n; i ++) {
            rlt += C(sum + n - 1, n - 1);
            if (rlt >= mod) rlt -= mod;
            sum += 1 - b[i];
        }
        printf("%d\n", rlt);
    }
}