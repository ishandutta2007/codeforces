#include <bits/stdc++.h>
using namespace std;

#define N 55

typedef long long ll;

const ll inf = 1e18;

int n, K, hb[N];
ll bound[N][2], c[N], dp[N][N][N][4][4];

void chkmin(ll &x, ll y) {
    if (x > y) x = y;
}

ll dfs(int k, int l, int r, int stl, int str) {
    ll &val = dp[k][l][r][stl][str];
    if (val != -1) return val;
    if (k == K) val = l + 1 == r ? 0 : inf;
    else val = dfs(k + 1, l, r, stl & 2, str & 2) + (l && r <= n && bool((((bound[l][stl>>1] ^ bound[r][str>>1]) >> k) ^ stl ^ str) & 1)) * c[k];
    for (int md = l + 1; md < r; md ++) {
        if (hb[md] > k) for (int z = 0; z < 2; z ++) if ((bound[md][z] >> k & 1) == z) chkmin(val, dfs(k, l, md, stl, z << 1 | 1) + dfs(k, md, r, z << 1 | 1, str));
    }


    return val;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i ++) {
        scanf("%I64d %I64d", &bound[i][0], &bound[i][1]);
        bound[i][0] --, bound[i][1] ++;
        hb[i] = __lg(bound[i][0] ^ bound[i][1]);
    }
    for (int i = 0; i < K; i ++) scanf("%I64d", &c[i]);
    printf("%I64d\n", dfs(0, 0, n + 1, 0, 0));

    return 0;
}