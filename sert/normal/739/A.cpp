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

const int N = 1e6 + 34;

int main() {
    init();
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    int minlen = n;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &l, &r);
        minlen = min(minlen, r - l + 1);
    }
    printf("%d\n", minlen);
    for (int i = 0; i < n; i++)
        printf("%d ", i % minlen);
    return 0;
}