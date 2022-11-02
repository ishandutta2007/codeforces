#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define K 35

const int INF = 1e9;
typedef long long ll;

int n;
int f[N], w[N];
ll k;
int mn[N][K], nxt[N][K];
ll sum[N][K];
int mans[N];
ll sans[N];

int main() {
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &f[i]);
        nxt[i][0] = f[i];
    }
    for (int i = 0; i < n; i ++) {
        scanf("%d", &w[i]);
        mn[i][0] = sum[i][0] = w[i];
    }
    for (int j = 1; j < K; j ++) {
        for (int i = 0; i < n; i ++) {
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
            mn[i][j] = min(mn[i][j-1], mn[nxt[i][j-1]][j-1]);
            sum[i][j] = sum[i][j-1] + sum[nxt[i][j-1]][j-1];
        }
    }
    for (int i = 0; i < n; i ++) {
        mans[i] = INF;
        int now = i;
        for (int j = 0; j < K; j ++) {
            if (k & (1ll << j)) {
                mans[i] = min(mans[i], mn[now][j]);
                sans[i] += sum[now][j];
                now = nxt[now][j];
            }
        }
        printf("%I64d %d\n", sans[i], mans[i]);
    }
    return 0;
}