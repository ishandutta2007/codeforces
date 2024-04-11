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

int n, x, a[N], b[N];
ll ans;

int main() {
    init();
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i] ^ x]++;
    }

    for (int i = 0; i < n; i++) {
        if (x)
            ans += b[a[i]];
        else
            ans += b[a[i]] - 1;
    }
    cout << ans / 2;

    return 0;
}