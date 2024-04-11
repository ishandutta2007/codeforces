#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

void in(int& a)
{
    scanf("%d", &a);
}

void in(ll& a)
{
#ifdef ONLINE_JUDGE
    scanf("%I64d", &a);
#else
    scanf("%lld", &a);
#endif
}

void in(char* a)
{
    scanf("%s", a);
}

void out(int a)
{
    printf("%d ", a);
}

void out(ll a)
{
    printf("%lld ", a);
}

void out(const char* a)
{
    printf("%s ", a);
}

void newline(void)
{
    printf("\n");
}

template<class T> T gcd(T a, T b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Insert correct MOD value here!
#define MOD 1000000007
// 998244353, ....
// Insert correct MOD value here!
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
#define inv(a) fpow(a, MOD-2)
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

bool* filter_primes(int max_value)
{
    bool* composite = new bool[max_value + 10];
    for (int i = 1; i <= max_value; i++) composite[i] = false;
    for (int i = 2; i <= max_value; i++) {
        if (composite[i]) continue;
        for (int j = 2; i * j <= max_value; j++) {
            composite[i * j] = true;
        }
    }
    for (int i = 2; i <= max_value; i++) composite[i] = !composite[i];
    composite[1] = false;
    return composite;
}

int n, I;
int a[400005];
int log2up[400005];

int maxdisvals;

bool check(int maxchange)
{
    /* interval size >= n - maxchange
     * log2up(disvals) * n <= I */
    int l = 1, r = 1;
    int disvals = 1;
    while (r <= n) {
        r++;
        if (a[r] != a[r-1]) disvals++;
        if (r - l + 1 > n - maxchange) {
            if (a[l] != a[l+1]) disvals--;
            l++;
        }
        //printf("%d: %d %d %d\n", maxchange, l, r, disvals);
        if (r - l + 1 == n - maxchange && log2up[disvals] * n <= I) return true;
    }
    return false;
}

int main()
{
    in(n); in(I);
    I *= 8;
    for (int i = 1; i <= n; i++) in(a[i]);
    sort(a + 1, a + n + 1);
    for (int K = 1; K <= n; K++) {
        for (int k = 20; k >= 0; k--) {
            if (K <= (1 << k)) log2up[K] = k;
        }
        //printf("%d ", log2up[K]);
    }
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    out(l);
    return 0;
}

/* Before Submitting:
 * 1. Did the program use loop counters correctly?
 * 2. Does the program have variable name conflicts?
 * 3. Are all the arrays big enough?
 * 4. Did you use the correct integer type?
 * 5. Did you type incorrect variable names?
 * 6. Are you sure that your design is correct?
 *
 */