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

int n, k, l, r, a[N], cur, sum;

int main() {
    init();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    while (k--) {
        cin >> l >> r;
        cur = a[r] - a[l - 1];
        sum += max(cur, 0);
    }
    cout << sum;

    return 0;
}