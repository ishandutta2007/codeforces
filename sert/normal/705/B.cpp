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

const int N = 1e3 + 34;

int n, x, ans = 2;

int main() {
    init();

    cin >> n;
    while (n--) {
        cin >> x;
        if (x % 2 == 0) ans = 3 - ans;
        cout << ans << " ";
    }

    return 0;
}