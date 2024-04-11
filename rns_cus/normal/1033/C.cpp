#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N], id[N];
char dp[N];

bool cmp(int i, int j) {
    return a[i] > a[j];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]), id[i] = i;
    sort(id, id + n, cmp);
    for (int i = 0; i < n; i ++) {
        bool fg = 1;
        for (int k = id[i] - a[id[i]]; k >= 0; k -= a[id[i]]) {
            if (a[k] > a[id[i]] && dp[k] == 'B') fg = 0;
        }
        for (int k = id[i] + a[id[i]]; k < n; k += a[id[i]]) {
            if (a[k] > a[id[i]] && dp[k] == 'B') fg = 0;
        }
        dp[id[i]] = 'A' + fg;
    }
    puts(dp);
}