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

int uf[4005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
}

int r, c;
char grid[2005][2005];
char grid2[2005][2005];
char tmp[2005];

#define flip(c) ((c)=='0'?'1':'0')

int pwr2[4000005];
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int f[2005][2];

int siz[4005], comp1[4005], compq[4005], compedges[4005];

void ones_cleanup()
{
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                if (grid[r][j] != '?') grid[r][j] = flip(grid[r][j]);
                if (grid[i][c] != '?') grid[i][c] = flip(grid[i][c]);
                if (grid[r][c] != '?') grid[r][c] = flip(grid[r][c]);
            }
        }
    }
}

int solve()
{
    for (int i = 1; i <= r + c; i++) {
        siz[i] = comp1[i] = compq[i] = 0;
    }
    for (int i = 1; i < r; i++) {
        if (grid[i][c] == '1') comp1[fin(i)]++;
        if (grid[i][c] == '?') compq[fin(i)]++;
    }
    for (int i = 1; i < c; i++) {
        if (grid[r][i] == '1') comp1[fin(r + i)]++;
        if (grid[r][i] == '?') compq[fin(r + i)]++;
    }
    int ans = 1;
    for (int i = 1; i <= r + c; i++) {
        siz[fin(i)]++;
    }
    for (int i = 1; i <= r + c; i++) {
        if (fin(i) != i) continue;
        if (comp1[i] % 2 && (!compq[i])) {
            ans = 0;
        } else {
            ans = mul(ans, (compq[i] ? pwr2[compq[i] - 1] : 1));
            ans = mul(ans, pwr2[compedges[i] - (siz[i] - 1)]);
        }
    }
    return ans;
}

int main()
{
    for (int i = 1; i <= 4000; i++) uf[i] = i;
    pwr2[0] = 1;
    for (int i = 1; i <= 4000000; i++) {
        pwr2[i] = pwr2[i-1] * 2;
        if (pwr2[i] >= MOD) pwr2[i] -= MOD;
    }
    scanf("%d%d", &r, &c);
    int qcnt = 0;
    for (int i = 1; i <= r; i++) {
        scanf("%s", tmp + 1);
        for (int j = 1; j <= c; j++) {
            grid[i][j] = tmp[j];
            if (grid[i][j] == '?') qcnt++;
        }
    }
    int ans = 0;
    if (r % 2 == 0 && c % 2 == 0) {
        ans = pwr2[qcnt];
    } else {
        if (r % 2 == 1) {
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    grid2[j][i] = grid[i][j];
                }
            }
            swap(r, c);
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    grid[i][j] = grid2[i][j];
                }
            }
        }
        if (r % 2 == 0) {
            int odd = 1, even = 1;
            for (int i = 1; i <= r; i++) {
                int qs = 0;
                int ones = 0;
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] == '1') ones++;
                    if (grid[i][j] == '?') qs++;
                }
                if (qs) {
                    odd = mul(odd, pwr2[qs - 1]);
                    even = mul(even, pwr2[qs - 1]);
                } else {
                    if (ones % 2) even = 0;
                    else odd = 0;
                }
            }
            ans = (odd + even) % MOD;
        } else {
            ones_cleanup();
            if (!qcnt) {
                int cnt1 = 0;
                for (int i = 1; i <= r; i++) {
                    for (int j = 1; j <= c; j++) {
                        if (i == r || j == c) {
                            if (grid[i][j] == '1') cnt1++;
                        }
                    }
                }
                printf("%d", (cnt1 == 0 || cnt1 == r + c - 1 ? 1 : 0));
                return 0;
            }
            int qx = 0, qy = 0;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (grid[i][j] == '?') {
                        qx = i; qy = j;
                    }
                }
            }
            if (qx != r) {
                for (int i = 1; i <= c; i++) {
                    swap(grid[qx][i], grid[r][i]);
                }
            }
            if (qy != c) {
                for (int i = 1; i <= r; i++) {
                    swap(grid[i][qy], grid[i][c]);
                }
            }
            ones_cleanup();
            /*for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    printf("%c", grid[i][j]);
                }
                printf("\n");
            }*/
            for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    if (grid[i][j] == '?') {
                        un(i, r + j);
                    }
                }
            }
            for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    if (grid[i][j] == '?') {
                        compedges[fin(i)]++;
                    }
                }
            }
            ans = solve();
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (i == r || j == c) {
                        if (grid[i][j] != '?')
                            grid[i][j] = flip(grid[i][j]);
                    }
                }
            }
            ans += solve();
            if (ans >= MOD) ans -= MOD;
        }
    }
    printf("%d", ans);
    return 0;
}