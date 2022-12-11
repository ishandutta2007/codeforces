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
const int N = (int)1e5 + 34;
const int INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;

int a[N];
int n, x, ans = 1, cur;

int main() {
    init();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }

    for (int i = 2; i < N; i++) {
        cur = 0;
        for (int j = i; j < N; j += i)
            cur += a[j];
        ans = max(ans, cur);
    }

    printf("%d\n", ans);

    return 0;
}