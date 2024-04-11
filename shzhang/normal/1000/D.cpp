#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long
#define MOD 998244353

int n;
int f[1005][1005];
int a[1005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i+1][j] += f[i][j];
            if (f[i+1][j] >= MOD) f[i+1][j] -= MOD;
            f[i+1][j-1] += f[i][j];
            if (f[i+1][j-1] >= MOD) f[i+1][j-1] -= MOD;
        }
        f[i+1][0] += f[i][0];
        if (f[i+1][0] >= MOD) f[i+1][0] -= MOD;
        if (1 <= a[i+1] && a[i+1] <= n) {
            f[i+1][a[i+1]] += f[i][0];
            if (f[i+1][a[i+1]] >= MOD) f[i+1][a[i+1]] -= MOD;
        }
    }
    f[n][0]--;
    if (f[n][0] < 0) f[n][0] += MOD;
    printf("%d", f[n][0]);
    return 0;
}