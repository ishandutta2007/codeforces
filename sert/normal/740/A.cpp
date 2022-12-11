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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 1e18, nn, cc;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
    for (int k = 0; k < 10; k++) {
        nn = n + i + j * 2 + k * 3;
        cc = a * i + b * j + c * k;
        if (nn % 4 == 0 && cc < ans)
            ans = cc;
    }
    cout << ans;
    return 0;
}