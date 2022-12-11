#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 3;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ll mx = max(max(a + b, a + c), max(d + b, d + c));
    ll mn = min(min(a + b, a + c), min(d + b, d + c));

    cout << max(0ll, (n - mx + mn) * n);

    return 0;
}