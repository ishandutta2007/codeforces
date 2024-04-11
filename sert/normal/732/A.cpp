#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;

int main() {
    init();
    ll n, c;
    cin >> n >> c;
    ll x = n;
    ll ans = 1;
    while (x % 10 != c && x % 10) {
        x += n;
        ans++;
    }
    cout << ans;

    return 0;
}