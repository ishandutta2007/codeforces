#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
const int N = (int)2e5 + 34;
int a[N], sp[N], sf[N];
int q, n, ans = N, tmp;

int main() {
    init();
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    if (n == 1) {
        printf("%d", !!a[0]);
        return 0;
    }

    q--;
    if (a[q]) {
        a[q] = 0;
        tmp++;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && i != q)
            a[i] = n;
        sf[a[i]]++;
    }
    sp[0] = 0;
    for (int i = 1; i <= n; i++)
        sp[i] = sp[i - 1] + !sf[i];
    for (int i = n - 1; i >= 0; i--)
        sf[i] += sf[i + 1];

    for (int i = 1; i < n; i++)
        ans = min(ans, max(sp[i], sf[i + 1]));

    printf("%d\n", ans + tmp);

    return 0;
}