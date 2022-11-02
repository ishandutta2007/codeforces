#include <bits/stdc++.h>
using namespace std;

#define N 35005
#define K 55

int n, k;
int a[N], last[N], prv[N];
int dp[K][N];

int mx[N<<2], add[N<<2];

void push_up(int id) {
    mx[id] = max(mx[id<<1], mx[id<<1|1]);
}

void add_delta(int id, int val) {
    add[id] += val;
    mx[id] += val;
}

void push_down(int id) {
    if (add[id]) {
        add_delta(id << 1, add[id]);
        add_delta(id << 1 | 1, add[id]);
        add[id] = 0;
    }
}

void modify(int L, int R, int val, int l, int r, int id) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
        add_delta(id, val);
        return;
    }
    push_down(id);
    int m = l + r >> 1;
    modify(L, R, val, l, m, id << 1);
    modify(L, R, val, m + 1, r, id << 1 | 1);
    push_up(id);
}

int query(int L, int R, int l, int r, int id) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) {
        return mx[id];
    }
    push_down(id);
    int m = l + r >> 1;
    return max(query(L, R, l, m, id << 1), query(L, R, m + 1, r, id << 1 | 1));
}

void calc_dp() {
    for (int i = 1; i <= k; i ++) {
        memset(mx, 0, sizeof mx);
        memset(add, 0, sizeof add);
        for (int j = 1; j <= n; j ++) {
            modify(prv[j], j - 1, 1, 0, n, 1);
            dp[i][j] = query(0, j - 1, 0, n, 1);
            modify(j, j, dp[i-1][j], 0, n, 1);
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        prv[i] = last[a[i]];
        last[a[i]] = i;
    }
    calc_dp();
    printf("%d\n", dp[k][n]);
}