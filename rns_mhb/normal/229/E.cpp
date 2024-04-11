#include <bits/stdc++.h>
using namespace std;

#define N 1005
#define x first
#define y second

typedef pair<int, int> pii;
typedef long double ld;
int n, m, cnt, r;
int sz[N], a[N];
pii p[N];
bool fg[N];
vector<int> v[N];
ld c[N][N];
ld dp[N][N];

void init() {
    c[0][0] = 1;
    for (int i = 1; i < N; i ++)
    for (int j = 0; j < N; j ++) {
        if (j > i) {
            c[i][j] = 0;
            continue;
        }
        if (!j) {
            c[i][j] = 1;
            continue;
        }
        c[i][j] = c[i-1][j-1] * j / i;
    }
}

ld ans;
ld p1[N], p2[N];

void calc_dp() {
    dp[0][0] = 1;
    for (int i = 1; i <= cnt; i ++) {
        for (int j = 0; j <= cnt; j ++) {
            if (j > i) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j] * p1[i];
            if (j) dp[i][j] += dp[i-1][j-1] * p2[i];
        }
    }
}

int main() {
    init();
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &sz[i]);
        a[i] = sz[i];
        for (int j = 0; j < sz[i]; j ++) {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
            p[cnt++] = pii(x, i);
        }
        sort(v[i].begin(), v[i].end());
    }
    sort(p, p + cnt);
    int lim = p[cnt-n].x;
    r = 0;
    for (int i = 1; i <= m; i ++) {
        a[i] = 0;
        fg[i] = 0;
        while (a[i] < sz[i] && v[i][sz[i]-1-a[i]] >= lim) {
            a[i] ++;
            if (v[i][sz[i]-a[i]] == lim) fg[i] = 1;
        }
        r += a[i] - fg[i];
    }
    r = n - r;
    ans = 1;
    cnt = 0;
    for (int i = 1; i <= m; i ++) {
        if (!fg[i]) {
            ans *= c[sz[i]][a[i]];
            continue;
        }
        cnt ++;
        p1[cnt] = c[sz[i]][a[i]-1], p2[cnt] = c[sz[i]][a[i]];
    }
    calc_dp();
    ans *= dp[cnt][r];
    ans *= c[cnt][r];
    printf("%.12lf\n", (double)ans);
    return 0;
}