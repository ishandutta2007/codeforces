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
    //init();
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 2;
        return 0;
    }
    if (n == 2) {
        cout << "2\n17\n";
        return 0;
    }

    cout << "2\n17\n";
    for (ll i = 3; i <= n; i++) {
        cout << i * (i + 1) * (i + 1) - i + 1 << "\n";
    }

    return 0;
}