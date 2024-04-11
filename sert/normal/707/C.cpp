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



int main() {
    //init();

    ll n, m = 1, x;
    cin >> n;

    if (n < 3) {
        cout << "-1\n";
        return 0;
    }

    while (true) {
        if (n == 4) {
            cout << 3 * m << " " << 5 * m << "\n";
            return 0;
        }
        if (n % 2) {
            x = n * n / 2;
            cout << m * x << " " << m * (x + 1) << "\n";
            return 0;
        }
        n /= 2;
        m *= 2;
    }

    return 0;
}