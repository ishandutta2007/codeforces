#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>

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

int n, m, k;
int b[100005];
int gap[100005];

int main()
{
    in(n); in(m); in(k);
    for (int i = 1; i <= n; i++) in(b[i]);
    for (int i = 1; i < n; i++) gap[i] = b[i+1] - b[i] - 1;
    sort(gap + 1, gap + n);
    int ans = n;
    for (int i = 1; i <= n - k; i++) ans += gap[i];
    out(ans);
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