#include <bits/stdc++.h>
using namespace std;

#define N 200200

typedef long long ll;

int n, cnt[66];
ll b[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%I64d", &b[i]), cnt[__builtin_ctzll(b[i])] ++;
    int mx = 0;
    for (int i = 0; i < 66; i ++) mx = max(mx, cnt[i]);
    printf("%d\n", n - mx);
    int k;
    for (k = 0; k < 66; k ++) if (cnt[k] == mx) break;
    for (int i = 0; i < n; i ++) if (__builtin_ctzll(b[i]) != k) printf("%I64d ", b[i]);

    return 0;
}