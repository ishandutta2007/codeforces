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

ll gcd(ll a, ll b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    init();
    ll a[101], p, c, ans = 1, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        p = a[i];
        c = 1;
        while (p != i) {
            p = a[p];
            c++;
            if (c > n) {
                cout << -1;
                return 0;
            }
        }
        if (c % 2 == 0) c /= 2;
        ans = ans * c / gcd(ans, c);
    }
    cout << ans;
    return 0;
}