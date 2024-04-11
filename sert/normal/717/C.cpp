#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = (int)1e6 + 34;

int n;
ll ans, a[N];

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", a + i);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        ans += a[i] * a[n - i - 1];
    printf("%I64d\n", ans % 10007);

    return 0;
}