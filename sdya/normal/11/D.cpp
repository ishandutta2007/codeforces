#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int g[25][25];
int n, m;

long long dp[(1 << 19)][19];

long long calc(int mask, int k)
{
    if (dp[mask][k] != -1) return dp[mask][k];
    int start = 0;
    for (int i = 0; i < n; i ++)
        if ((mask & (1 << i)) == 0) {start = i; break;}

    int l = 0;
    for (int i = 0; i < n; i ++)
        if ((mask & (1 << i)) == 0) l ++;

    if (l == 2)
    {
        dp[mask][k] = g[start][k];
        return dp[mask][k];
    }

    dp[mask][k] = 0;
    int nmask = (mask | (1 << k));
    for (int i = start + 1; i < n; i ++)
        if ((mask & (1 << i)) == 0 && i != k && g[i][k])
            dp[mask][k] += calc(nmask, i);
    return dp[mask][k];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i ++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a - 1][b - 1] = g[b - 1][a - 1] = true;
    }

    for (int i = 0; i < (1 << n); i ++)
        for (int j = 0; j < n; j ++)
            dp[i][j] = -1;

    long long res = 0;
    for (int i = 0; i < (1 << n); i ++)
    {
        int start = 0;
        for (int j = 0; j < n; j ++)
            if ((i & (1 << j)) == 0) {start = j; break;}

        int l = 0;
        for (int j = 0; j < n; j ++)
            if ((i & (1 << j)) == 0) l ++;

        if (l <= 2) continue;

        for (int j = start + 1; j < n; j ++)
            if ((i & (1 << j)) == 0 && g[start][j]) res += calc(i, j);
    }

    cout << res / 2LL << endl;
    return 0;
}