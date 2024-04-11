#include <cstdio>
const int N = 1e5 + 34;
long long n, m, k, l[N], r[N], x[N], q, ans;
int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &k);
    for (int i = 0; i < m; i++)
        scanf("%I64d%I64d%I64d", &l[i], &r[i], &x[i]);
    for (int i = 0; i < k; i++) {
        scanf("%I64d", &q);
        for (int j = 0; j < m; j++)
            if (q >= l[j] && q <= r[j])
                ans += x[j] + q - l[j];
    }
    printf("%I64d\n", ans);
    return 0;
}