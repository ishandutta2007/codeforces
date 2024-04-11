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
#include <utility>
#include <random>
#include <chrono>

using namespace std;

#define ll long long

int n, k;
ll cur = 0;
ll a[55];
bool f[55][55];
vector<int> nxt[55];

bool test(void)
{
    for (int i = 0; i < 55; i++) nxt[i].clear();
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) f[i][j] = false;
    }
    for (int i = 1; i <= n; i++) {
        ll cursum = 0;
        for (int j = i; j <= n; j++) {
            cursum += a[j];
            if ((cursum & cur) == cur) {
                //printf("cur = %lld, %d %d\n", cur, i, j);
                nxt[i].push_back(j+1);
            }
        }
    }
    f[1][0] = true;
    for (int lvl = 0; lvl < k; lvl++) {
        for (int i = 1; i <= n; i++) {
            if (!f[i][lvl]) continue;
            for (int j = 0; j < nxt[i].size(); j++) {
                f[nxt[i][j]][lvl+1] = true;
            }
        }
    }
    return f[n+1][k];
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (ll i = 60; i >= 0; i--) {
        cur ^= 1LL << i;
        if (!test()) cur ^= 1LL << i;
    }
    printf("%lld", cur);
    return 0;
}