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

int n;

char s1[2005], s2[2005];
int ones1[2005], ones2[2005], q1[2005], q2[2005];

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int C[5005][5005];

int getc(int x, int y)
{
    if (y < 0 || y > x) return 0;
    return C[x][y];
}

void work()
{
    scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    for (int i = 1; i <= n; i += 2) {
        if (s1[i] == '1') s1[i] = '0';
        else if (s1[i] == '0') s1[i] = '1';
        if (s2[i] == '1') s2[i] = '0';
        else if (s2[i] == '0') s2[i] = '1';
    }
    for (int i = 1; i <= n; i++) {
        ones1[i] = ones1[i-1] + (s1[i] == '1' ? 1 : 0);
        ones2[i] = ones2[i-1] + (s2[i] == '1' ? 1 : 0);
        q1[i] = q1[i-1] + (s1[i] == '?' ? 1 : 0);
        q2[i] = q2[i-1] + (s2[i] == '?' ? 1 : 0);
    }
    //printf("%s %s\n", s1 + 1, s2 + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i] == '0' || s2[j] == '0') continue;
            int a = ones1[i-1], b = q1[i-1];
            int c = ones2[j-1], d = q2[j-1];
            int addv = getc(b+d, d-a+c);
            //printf("%d %d %d %d %d %d %d\n", i, j, a, b, c, d, getc(b+d, d-a+c));
            a = ones1[n] - ones1[i];
            b = q1[n] - q1[i];
            c = ones2[n] - ones2[j];
            d = q2[n] - q2[j];
            //printf("%d %d %d %d %d %d %d\n", i, j, a, b, c, d, getc(b+d, d-a+c));
            addv = mul(addv, getc(b+d, d-a+c));
            ans += mul(addv, max(j-i, i-j));
            if (ans >= MOD) ans -= MOD;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    C[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            if (C[i][j] >= MOD) C[i][j] -= MOD;
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}