#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

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

int need[1005][1005];

int h, w;

void quit()
{
    printf("0");
    exit(0);
}

int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
        int r;
        scanf("%d", &r);
        for (int j = 1; j <= r; j++) need[i][j] = 1;
        need[i][r+1] = 2;
    }
    for (int i = 1; i <= w; i++) {
        int c;
        scanf("%d", &c);
        for (int j = 1; j <= c; j++) {
            if (need[j][i] == 2) quit();
            need[j][i] = 1;
        }
        if (c+1 <= h && need[c+1][i] == 1) quit();
        need[c+1][i] = 2;
    }
    int cnt = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!need[i][j]) cnt++;
        }
    }
    printf("%d", fpow(2, cnt));
    return 0;
}