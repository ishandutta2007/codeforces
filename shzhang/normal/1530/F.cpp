#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

typedef unsigned int ull;
typedef unsigned long long L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 32) / b)) {}
	ull reduce(ull a) { // returns a modulo b
		ull q = (ull)((L(m) * a) >> 32);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};

FastMod F(31607);

#define MOD 31607
#define mul(a, b) (F.reduce((a) * (b)))

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

int n;
int a[25][25];
int inv[25][25];
int flag[25][25];
bool bits[25];

int prods[25];

int baseprod = 1;

void inc(int r, int c)
{
    if (!flag[r][c]) {
        baseprod = mul(baseprod, a[r][c]);
        prods[c] = mul(prods[c], inv[r][c]);
    }
    flag[r][c]++;
}

void dec(int r, int c)
{
    if (flag[r][c] == 1) {
        baseprod = mul(baseprod, inv[r][c]);
        prods[c] = mul(prods[c], a[r][c]);
    }
    flag[r][c]--;
}

int main()
{
    int inv10000 = fpow(10000, MOD - 2);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) prods[i] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(a[i][j]));
            a[i][j] = mul(a[i][j], inv10000);
            inv[i][j] = fpow(a[i][j], MOD - 2);
            prods[j] = mul(prods[j], a[i][j]);
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << (n + 2)); mask++) {
        int weight = 0;
        int topbit = 0;
        for (int i = n + 1; i >= 0; i--) {
            if (mask & (1 << i)) {
                weight++; topbit = i;
            }
            bits[i] = (mask & (1 << i));
        }
        /*bool diag1 = false, diag2 = false;
        if (bits[n]) diag1 = true;
        if (bits[n+1]) diag2 = true;*/

        if (mask > 0) {
            if (topbit == n + 1) {
                for (int j = 0; j < n; j++) inc(j, n - 1 - j);
            } else if (topbit == n) {
                for (int j = 0; j < n; j++) inc(j, j);
            } else {
                for (int j = 0; j < n; j++) inc(topbit, j);
            }
            for (int i = topbit - 1; i >= 0; i--) {
                if (i == n) {
                    for (int j = 0; j < n; j++) dec(j, j);
                } else {
                    for (int j = 0; j < n; j++) dec(i, j);
                }
            }
        }

        int val = baseprod;

        for (int i = 0; i < n; i++) {
            val = mul(val, prods[i] + MOD - 1);
        }
        if ((weight + n) % 2 == 1) {
            ans += val; if (ans >= MOD) ans -= MOD;
        } else {
            ans -= val; if (ans < 0) ans += MOD;
        }
    }
    ans++; if (ans >= MOD) ans -= MOD;
    printf("%d", ans);
    return 0;
}