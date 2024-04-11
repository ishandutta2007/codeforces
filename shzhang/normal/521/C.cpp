#include <cstdio>

using namespace std;

#define ll long long
#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int factorial[100005];
int inv_factorial[100005];
int seq[100005];
int pwr10[100005];
int n, k;
char s[100005];

int C(int a, int b)
{
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return mul(factorial[a], mul(inv_factorial[b], inv_factorial[a-b]));
}

int main()
{
    factorial[0] = pwr10[0] = 1;
    for (int i = 1; i <= 100000; i++) pwr10[i] = mul(10, pwr10[i-1]);
    for (int i = 1; i <= 100000; i++) factorial[i] = mul(factorial[i-1], i);
    inv_factorial[100000] = fpow(factorial[100000], MOD - 2);
    for (int i = 99999; i >= 0; i--) inv_factorial[i] = mul(inv_factorial[i+1], i+1);
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 0; i <= n - 2; i++) {
        seq[i] = mul(pwr10[i], C(n-i-2, k-1));
        if (i >= 1) {
            seq[i] += seq[i-1]; if (seq[i] >= MOD) seq[i] -= MOD;
        }
        //printf("%d ", seq[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += mul(s[i] - '0', mul(pwr10[n-i], C(i-1, k)) + (n-i-1 >= 0 ? seq[n-i-1] : 0));
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d", ans);
    return 0;
}