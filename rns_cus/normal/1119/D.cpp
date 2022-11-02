#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, q;
long long s[N], d[N], sum[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) scanf("%I64d", &s[i]);
    sort(s, s + n);
    for (int i = 1; i < n; i ++) d[i] = s[i] - s[i-1];
    sort(d + 1, d + n);
    for (int i = n - 1; i > 0; i --) sum[i] = sum[i+1] + d[i];
    scanf("%d", &q);
    while (q --) {
        long long l, r;
        scanf("%I64d %I64d", &l, &r);
        long long rlt = s[n-1] + r - s[0] - l + 1;
        int i = lower_bound(d + 1, d + n, r - l + 1) - d;
        cout << rlt - sum[i] + 1ll * (r - l + 1) * (n - i) << ' ';
    }
}