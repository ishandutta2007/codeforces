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
const ld EPS = 1e-12;
const ll md = (int)1e9 + 7;
const ll o_10e6 = 397802501;
const int N = (int)1e5 + 34;

int n, mx, sum, x;

int main() {
    init();

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }
    cout << mx * n - sum;
    return 0;
}