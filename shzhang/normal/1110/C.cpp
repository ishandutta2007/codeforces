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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int q;

int vals[] = {0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89,
     1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101,
     178481, 5592405, 1082401};

int main()
{
    in(q);
    for (int i = 1; i <= q; i++) {
        int a;
        in(a);
        if (a == 2) {printf("3\n"); continue;}
        if ((a & (a + 1)) == 0) {
            int highestbit;
            for (int j = 0; j < 30; j++) {
                if ((a + 1) & (1 << j)) highestbit = j;
            }
            printf("%d\n", vals[highestbit]);
        } else {
            int highestbit = 0;
            for (int j = 0; j < 30; j++) {
                if (a & (1 << j)) highestbit = (1 << j);
            }
            out(highestbit * 2 - 1); newline();
        }
    }
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