#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

long long n, b, p, ans, st;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> b >> p;
    ll nn = n;

    while (n > 1) {
        st = 2;
        while (st * 2 <= n) st *= 2;
        ans += (st / 2) * (2 * b + 1);
        n -= st / 2;
    }

    cout << ans << " " << nn * p;


    return 0;
}