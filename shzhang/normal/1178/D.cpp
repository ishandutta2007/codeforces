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
#define MOD 998244353
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

int n;

int edgecnt = 0;
bool* isprime;

int edges[1000005][2];

void addedge(int u, int v)
{
    edgecnt++;
    edges[edgecnt][0] = u;
    edges[edgecnt][1] = v;
}

int main()
{
    isprime = filter_primes(1500000);
    in(n);
    if (n == 4) {
        out(5); newline();
        out(1); out(2); newline();
        out(1); out(3); newline();
        out(2); out(3); newline();
        out(2); out(4); newline();
        out(3); out(4); newline();
        return 0;
    }
    if (n % 3 == 0) {
        for (int i = 1; i < n; i += 3) {
            addedge(i, i+1);
            addedge(i+1, i+2);
            addedge(i+2, i);
        }
    } else if (n % 3 == 1) {
        for (int i = 1; i < n - 4; i += 3) {
            addedge(i, i+1);
            addedge(i+1, i+2);
            addedge(i+2, i);
        }
        addedge(n-3, n-2);
        addedge(n-2, n-1);
        addedge(n-1, n);
        addedge(n, n-3);
    } else {
        for (int i = 1; i < n - 5; i += 3) {
            addedge(i, i+1);
            addedge(i+1, i+2);
            addedge(i+2, i);
        }
        addedge(n-4, n-3);
        addedge(n-3, n-2);
        addedge(n-2, n-1);
        addedge(n-1, n);
        addedge(n, n-4);
    }
    int cur = 1;
    bool cur2used = false;
    while (!isprime[edgecnt]) {
        addedge(cur, cur+3);
        cur += 6;
        if (cur >= n - 5) {
            if (!cur2used) {
                cur = 2; cur2used = true;
            } else {
                cur = 3;
            }
        }
        //out(":"); out(cur); newline();
    }
    out(edgecnt); newline();
    for (int i = 1; i <= edgecnt; i++) {
        out(edges[i][0]); out(edges[i][1]); newline();
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