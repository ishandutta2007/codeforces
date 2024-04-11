#include <bits/stdc++.h>
using namespace std;

#define N 1048600
#define MOD 1000000007

int n, m, ans, tgt;
int a[N];
int e[N], bit[N];
char ch;

void init() {
    e[0] = 1;
    for (int i = 1; i <= n; i ++) e[i] = 2ll * e[i-1] % MOD;
    bit[0] = 0;
    for (int i = 1; i < (1 << m); i ++) bit[i] = bit[i>>1] + (i & 1);
}

int main() {
    scanf("%d", &n);
    m = 20;
    init();
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        x = ((1 << m) - 1) ^ x;
        a[x] ++;
    }
    tgt = (1 << m) - 1;
    for (int i = 0; i < m; i ++)
    for (int j = 0; j < (1 << m); j ++) {
        if (j & (1 << i)) {
            a[j] += a[j^(1<<i)];
        }
    }
    for (int i = 0; i < (1 << m); i ++) {
        if ((i & tgt) == i) {
            ans += e[a[i]] * (bit[tgt^i] & 1 ? -1 : 1);
            ans %= MOD;
        }
    }
    printf("%d\n", (ans + MOD) % MOD);
}