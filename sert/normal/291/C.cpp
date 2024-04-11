#include <cstdio>
#include <algorithm>

typedef long long ll;
const ll N = 1e5 + 34;

ll n, l, d, a[N];
ll mn, mx, ans = -1, kol, o, k, h1, h2, h3, h4;

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%I64d%I64d\n", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%I64d.%I64d.%I64d.%I64d\n", &h1, &h2, &h3, &h4);
        a[i] = ((h1 * 256 + h2) * 256 + h3) * 256 + h4;
    }

    std::sort(a, a + n);

    for (int i = 31; i >= 1; i--) {
        for (int j = 0; j < n; j++)
            a[j] /= 2;
        kol = 1;
        for (int j = 1; j < n; j++)
            if (a[j] != a[j - 1])
                kol++;
        if (kol == k)
            ans = i;
    }

    if (ans == -1) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < ans; i++)
        o = o * 2 + 1;
    for (int i = ans; i < 32; i++)
        o *= 2;
    h4 = o % 256;
    o /= 256;
    h3 = o % 256;
    o /= 256;
    h2 = o % 256;
    o /= 256;
    h1 = o;
    printf("%I64d.%I64d.%I64d.%I64d\n", h1, h2, h3, h4);

    return 0;
}